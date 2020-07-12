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

using ll = long long;

using namespace std;

struct S {
  ll cost;
  ll value;
  bool operator<(const S& s) const {
    // return cost > s.cost;
    if (cost != s.cost) {
      return cost > s.cost;
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
    if (here.value == 0) {
      ll x = here.value;
      while (x != N) {
        DBG(x);
        x = prev[x];
      }
      cout << here.cost << endl;
      break;
    }
    auto push = [&prev, &seen, &que, &here](ll cost, ll value) {
                  if (value < 0) return;
                  S there = {here.cost + cost, value};
                  auto it = seen.find(there.value);
                  if (it != seen.end() && it->second <= there.cost) {
                    return;
                  }
                  seen[there.value] = there.cost;
                  prev[there.value] = here.value;
                  que.push(there);
                };
    if (here.value % 2 == 0) {
      push(A, here.value / 2);
    }
    if (here.value % 3 == 0) {
      push(B, here.value / 3);
    }
    if (here.value % 5 == 0) {
      push(C, here.value / 5);
    }

    for (ll d = -4; d <= 4; ++d) {
      ll value = here.value + d;
      ll mods[] = {2, 3, 5};
      REP(i, 3) {
        ll m = mods[i];
        if (here.value % m != 0 && value % m == 0 && abs(d) < m) {
          push(D * abs(d), value);
        }
      }
    }

    /*
    if (here.value % 2 != 0) {
      push(D, here.value - 1);
      push(D, here.value + 1);
    }
    if (ll d = here.value % 3; d != 0) {
      push(D * d, here.value - d);
      push(D * (3 - d), here.value + (3 - d));
    }
    if (ll d = here.value % 5; d != 0) {
      push(D * d, here.value - d);
      push(D * (5 - d), here.value + (5 - d));
    }
    */

    if (D * here.value > 0) {
      push(D * here.value, 0);
    }
  }
}

int main() {
  int T;
  cin >> T;
  REP(t, T) {
    cin >> N >> A >> B >> C >> D;
    solve();
    // if (t == 2) break;
  }
}
