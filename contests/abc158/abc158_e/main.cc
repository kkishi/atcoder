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

ll dp[2][10000];

int main() {
  int N, P;
  cin >> N >> P;
  string S;
  cin >> S;
  DBG(S);
  ll ans = 0;
  REP(i, N) {
    int curr = i % 2;
    int prev = 1 - curr;
    memset(dp[curr], 0, sizeof(dp[curr]));
    int d = S[i] - '0';
    DBG(d, P);
    dp[curr][d % P]++;
    REP(j, P) { dp[curr][(j * 10 + d) % P] += dp[prev][j]; }
    DBG(i, curr, prev);
    REP(j, P) DBG(j, dp[curr][j]);
    ans += dp[curr][0];
  }
  cout << ans << endl;
}
