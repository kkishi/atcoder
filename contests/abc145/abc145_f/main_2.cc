#include <bits/stdc++.h>

template <typename T>
std::vector<T> Compress(std::vector<T> v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  return v;
}

template <typename T>
T Uncompress(const std::vector<T>& v, T x) {
  return std::lower_bound(v.begin(), v.end(), x) - v.begin();
}

template <typename T>
std::function<T(T)> Uncompressor(const std::vector<T>& v) {
  return [&v](T i) -> T { return Uncompress(v, i); };
}

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

const ll INF = 1LL<<60;

void setmin(ll& a, ll b) {
  if (a > b) a = b;
}

int main() {
  in(ll, n, K);
  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  h.push_back(0);
  vector<ll> hc = Compress(h);

  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(K + 1, vector<ll>(hc.size(), INF)));
  dp[0][0][0] = 0;
  rep(i, n) rep(j, K + 1) rep(k, hc.size()) {
    if (j < K) {
      setmin(dp[i + 1][j + 1][k], dp[i][j][k]);
    }
    setmin(dp[i + 1][j][Uncompress(hc, h[i])], dp[i][j][k] + max(0LL, h[i] - hc[k]));
  }
  ll ans = INF;
  rep(i, K + 1) rep(j, hc.size()) setmin(ans, dp[n][i][j]);
  out(ans);
}
