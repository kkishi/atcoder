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
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

template <typename T>
void setmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <typename T>
void setmax(T& a, const T& b) {
  if (a < b) a = b;
}

using ll = long long;

using namespace std;

struct S {
  ll cost;
  ll value;
  bool operator<(const S& s) const {
    return cost > s.cost;
    if (cost != s.cost) {
      cost > s.cost;
    }
    return value > s.value;
  }
};

ll N, A, B, C, D;

void solve() {
  DBG(N);

  map<ll, ll> prev;
  map<ll, ll> seen;
  seen[N] = 0;

  priority_queue<S> que;
  que.push({0, N});

  while (!que.empty()) {
    S here = que.top();
    que.pop();
    DBG(here.cost, here.value, que.size(), seen.size());
    if (here.value == 1) {
      ll x = here.value;
      while (x != N) {
        DBG(x);
        x = prev[x];
      }
      cout << (here.cost + D) << endl;
      break;
    }
    auto push = [&prev, &seen, &que, &here](const S& there) {
                  auto it = seen.find(there.value);
                  if (it != seen.end() && it->second < there.cost) {
                    return;
                  }
                  seen[there.value] = there.cost;
                  prev[there.value] = here.value;
                  que.push(there);
                };
    if (here.value % 2 == 0) {
      ll dec = here.value / 2;
      ll cost = min(dec * D, A);
      push({here.cost + cost, here.value / 2});
    }
    if (here.value % 3 == 0) {
      ll dec = here.value / 3 * 2;
      ll cost = min(dec * D, B);
      DBG(dec, cost);
      push({here.cost + cost, here.value / 3});
    }
    if (here.value % 5 == 0) {
      ll dec = here.value / 5 * 4;
      ll cost = min(dec * D, C);
      push({here.cost + cost, here.value / 5});
    }
    push({here.cost + D, here.value + 1});
    push({here.cost + D, here.value - 1});
  }
}

int main() {
  int T;
  cin >> T;
  REP(t, T) {
    cin >> N >> A >> B >> C >> D;
    solve();
  }
}
