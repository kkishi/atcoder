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

int main() {
  in(ll, n);
  vector<ll> x(n), y(n);
  vector<char> u(n);
  rep(i, n) cin >> x[i] >> y[i] >> u[i];

  const ll M = 400001;
  const ll inf = numeric_limits<ll>::max();
  ll t = inf;
  rep(rot, 4) {
    // R L
    {
      vector<vector<ll>> r(M);
      rep(i, n) if (u[i] == 'R') r[y[i]].push_back(x[i]);
      rep(i, M) sort(all(r[i]));
      rep(i, n) if (u[i] == 'L') {
        const auto& ri = r[y[i]];
        if (ri.empty()) continue;
        auto it = lower_bound(all(ri), x[i]);
        if (it != ri.begin()) {
          if (ll d = x[i] - *(it - 1); d > 0) {
            t = min(t, d * 10 / 2);
          }
        }
      }
    }
    // R U
    {
      vector<vector<ll>> r(M);
      rep(i, n) if (u[i] == 'R') r[x[i] + y[i]].push_back(x[i]);
      rep(i, M) sort(all(r[i]));
      rep(i, n) if (u[i] == 'U') {
        const auto& ri = r[x[i] + y[i]];
        if (ri.empty()) continue;
        auto it = lower_bound(all(ri), x[i]);
        if (it != ri.begin()) {
          if (ll d = x[i] - *(it - 1); d > 0) {
            t = min(t, d * 10);
          }
        }
      }
    }
    // Rotate 90 degrees.
    rep(i, n) {
      int nx = 200000 - y[i];
      int ny = x[i];
      x[i] = nx;
      y[i] = ny;
      u[i] =
          map<char, char>{{'R', 'U'}, {'L', 'D'}, {'U', 'L'}, {'D', 'R'}}[u[i]];
    }
  }
  if (t == inf) {
    out("SAFE");
  } else {
    out(t);
  }
}
