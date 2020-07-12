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

ll dp[1000001][2];

int main() {
  string N;
  cin >> N;

  dp[0][0] = 0;
  dp[0][1] = 1;
  REP(i, N.size()) {
    int digit = N[i] - '0';
    dp[i + 1][0] = min(dp[i][0] + digit,
                       min(dp[i][1] + (10 - digit),
                           dp[i][1] + 1 + digit));
    dp[i + 1][1] = min(dp[i][0] + 1 + (9 - digit),
                       dp[i][1] + (9 - digit));
    /*
    if (digit == 0) {
      dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 1);
    }
    */
    DBG(i, N[i], dp[i + 1][0], dp[i + 1][1]);
  }
  cout << min(dp[N.size()][0], dp[N.size()][1] + 1) << endl;
}
