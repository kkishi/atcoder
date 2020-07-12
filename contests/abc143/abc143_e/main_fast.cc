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

ll dist[301][301];
State seens[301][301];

int main() {
  ll n, m, l;
  scanf("%lld %lld %lld", &n, &m, &l);

  rep(i, m) {
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    if (c <= l) {
      dist[a][b] = dist[b][a] = c;
    }
  }

  rep(i, n) {
    int city = i + 1;
    State init = {city, l, 0};

    State* seen = seens[city];
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
        State& s = seen[there.city];
        if (s.city == there.city && !(there < s)) continue;
        s = there;
        que.push(there);
      }
    }
  }
  ll q;
  scanf("%lld", &q);
  rep(i, q) {
    ll s, t;
    scanf("%lld %lld", &s, &t);
    State& st = seens[s][t];
    if (st.city == 0) {
      out(-1);
    } else {
      out(st.refueling);
    }
  }
}
