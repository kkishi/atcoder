#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

struct State {
  int city;
  ll remaining;
  ll refueling;
  bool operator<(const State& dp) const {
    if (refueling != dp.refueling) {
      return refueling < dp.refueling;
    }
    return remaining > dp.remaining;
  }
  bool operator>(const State& dp) const {
    return dp < *this;
  }
};

int main() {
  in(ll, n, m, l);

  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 0LL));
  rep(i, m) {
    in(ll, a, b, c);
    if (c <= l) {
      dist[a][b] = dist[b][a] = c;
    }
  }

  vector<map<int, State>> seens(n + 1);
  rep(i, n) {
    int city = i + 1;
    State init = {city, l, 0};

    map<int, State>& seen = seens[city];
    seen[city] = init;

    priority_queue<State, vector<State>, greater<State>> que;
    que.push(init);

    while (!que.empty()) {
      State here = que.top();
      que.pop();
      if (seen[here.city] < here) continue;
      rep(j, n) {
        State there = here;
        there.city = j + 1;
        if (here.city == there.city) continue;
        ll d = dist[here.city][there.city];
        if (d == 0) continue;
        there.remaining -= d;
        if (there.remaining < 0) {
          there.remaining = l - d;
          ++there.refueling;
        }
        const auto p = seen.find(there.city);
        if (p != seen.end() && !(there < p->second)) continue;
        seen[there.city] = there;
        que.push(there);
      }
    }
  }
  in(int, q);
  rep(i, q) {
    in(int, s, t);
    const auto p = seens[s].find(t);
    if (p == seens[s].end()) {
      out(-1);
    } else {
      out(p->second.refueling);
    }
  }
}
