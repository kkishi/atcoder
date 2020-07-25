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

template <typename T>
bool Setmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
T BinarySearch(T lo, T hi, std::function<bool(T)> pred) {
  while (lo + 1 < hi) {
    T mid = (hi - lo) / 2 + lo;
    if (pred(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main() {
  in(ll, n);
  vector<ll> x(n), y(n);
  vector<char> u(n);
  rep(i, n) cin >> x[i] >> y[i] >> u[i];

  const ll M = 400005;
  const ll inf = numeric_limits<ll>::max();
  ll t = inf;
  auto pi = [&](int i) { return x[i] + y[i]; };
  auto mi = [&](int i) { return x[i] + (200000 - y[i]); };
  // R L
  {
    vector<vector<ll>> r(M);
    rep(i, n) if (u[i] == 'R') r[y[i]].push_back(x[i]);
    rep(i, M) sort(all(r[i]));
    rep(i, n) if (u[i] == 'L') {
      const auto& ri = r[y[i]];
      if (ri.empty()) continue;
      int j =
          BinarySearch<int>(0, ri.size(), [&](int k) { return ri[k] < x[i]; });
      if (ri[j] < x[i]) {
        t = min(t, (x[i] - ri[j]) * 10 / 2);
      }
    }
  }
  // D U
  {
    vector<vector<ll>> r(M);
    rep(i, n) if (u[i] == 'U') r[x[i]].push_back(y[i]);
    rep(i, M) sort(all(r[i]));
    rep(i, n) if (u[i] == 'D') {
      const auto& ri = r[x[i]];
      if (ri.empty()) continue;
      int j =
          BinarySearch<int>(0, ri.size(), [&](int k) { return ri[k] < y[i]; });
      if (ri[j] < y[i]) {
        t = min(t, (y[i] - ri[j]) * 10 / 2);
      }
    }
  }
  // R U
  {
    vector<vector<ll>> r(M);
    rep(i, n) if (u[i] == 'R') r[pi(i)].push_back(x[i]);
    rep(i, M) sort(all(r[i]));
    rep(i, n) if (u[i] == 'U') {
      const auto& ri = r[pi(i)];
      if (ri.empty()) continue;
      dbg(ri.size(), x[i], ri[0]);
      int j =
          BinarySearch<int>(0, ri.size(), [&](int k) { return ri[k] < x[i]; });
      if (ri[j] < x[i]) {
        t = min(t, (x[i] - ri[j]) * 10);
      }
    }
  }
  // R D ?
  {
    vector<vector<ll>> r(M);
    rep(i, n) if (u[i] == 'R') r[mi(i)].push_back(x[i]);
    rep(i, M) sort(all(r[i]));
    rep(i, n) if (u[i] == 'D') {
      const auto& ri = r[mi(i)];
      if (ri.empty()) continue;
      dbg(ri.size(), x[i], ri[0]);
      int j =
          BinarySearch<int>(0, ri.size(), [&](int k) { return ri[k] < x[i]; });
      if (ri[j] < x[i]) {
        t = min(t, (x[i] - ri[j]) * 10);
      }
    }
  }
  // L U
  {
    vector<vector<ll>> r(M);
    rep(i, n) if (u[i] == 'U') r[mi(i)].push_back(x[i]);
    rep(i, M) sort(all(r[i]));
    rep(i, n) if (u[i] == 'L') {
      const auto& ri = r[mi(i)];
      if (ri.empty()) continue;
      dbg(ri.size(), x[i], ri[0]);
      int j =
          BinarySearch<int>(0, ri.size(), [&](int k) { return ri[k] < x[i]; });
      if (ri[j] < x[i]) {
        t = min(t, (x[i] - ri[j]) * 10);
      }
    }
  }
  // L D ?
  {
    vector<vector<ll>> r(M);
    rep(i, n) if (u[i] == 'D') r[pi(i)].push_back(x[i]);
    rep(i, M) sort(all(r[i]));
    rep(i, n) if (u[i] == 'L') {
      const auto& ri = r[pi(i)];
      if (ri.empty()) continue;
      dbg(ri.size(), x[i], ri[0]);
      int j =
          BinarySearch<int>(0, ri.size(), [&](int k) { return ri[k] < x[i]; });
      if (ri[j] < x[i]) {
        t = min(t, (x[i] - ri[j]) * 10);
      }
    }
  }
  if (t == inf) {
    out("SAFE");
  } else {
    out(t);
  }
}
