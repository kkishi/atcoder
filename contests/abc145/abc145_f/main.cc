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

const ll INF = 1LL<<60;

void setmin(ll& a, ll b) {
  if (a > b) a = b;
}

int main() {
  in(ll, n, k);
  vector<ll> h(n + 4);
  rep(i, n) cin >> h[i + 2];  // h[i + 2] = height at 0
  // left, mid, prev
  // dp[i + 1][j][k]
  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(4, INF)));
  dp[0][0][1] = 0;
  rep(i, n) {
    rep(d, 4) {
      ll prev_height = d == 3 ? 0 : h[i + 2 - d];
      rep(e, 4) {
        ll curr_height = e == 3 ? 0 : h[i + 3 - e];
        rep(j, k + 1) {
          int nj = j + (e == 1 ? 0 : 1);
          if (nj > k) continue;
          setmin(dp[i + 1][nj][e], dp[i][j][d] + max(0LL, curr_height - prev_height));
        }
      }
    }
  }
  ll ans = INF;
  rep(i, k + 1) rep(j, 4) setmin(ans, dp[n][i][j]);
  out(ans);
}
