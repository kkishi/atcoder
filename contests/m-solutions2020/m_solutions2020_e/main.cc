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

int main() {
  in(ll, n);
  vector<ll> x(n), y(n), p(n);
  rep(i, n) cin >> x[i] >> y[i] >> p[i];
  vector<ll> ans(n + 1, numeric_limits<ll>::max());
  function<void(int, int, vector<ll>)> rec = [&](int depth, int k,
                                                 vector<ll> dist) {
    if (depth == n) {
      ll S = 0;
      rep(i, n) S += p[i] * dist[i];
      Setmin(ans[k], S);
      return;
    }
    rec(depth + 1, k, dist);
    {
      // x
      vector<ll> ndist = dist;
      rep(i, n) Setmin(ndist[i], abs(x[i] - x[depth]));
      rec(depth + 1, k + 1, ndist);
    }
    {
      // y
      vector<ll> ndist = dist;
      rep(i, n) Setmin(ndist[i], abs(y[i] - y[depth]));
      rec(depth + 1, k + 1, ndist);
    }
  };
  vector<ll> dist(n);
  rep(i, n) dist[i] = min(abs(x[i]), abs(y[i]));
  rec(0, 0, dist);
  for (int k = 0; k <= n; ++k) {
    out(ans[k]);
  }
}
