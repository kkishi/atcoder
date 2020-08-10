#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

int A[3000];

using modint = ModInt<998244353>;
modint dp[3001][3001];

int main() {
  int N, S;
  cin >> N >> S;
  rep(i, N) cin >> A[i];

  dp[0][0] = 1;
  modint ans = 0;
  rep(i, N) {
    rep(j, S + 1) {
      dp[i + 1][j] += dp[i][j];
      if (int nj = j + A[i]; nj <= S) {
        modint added = j == 0 ? i + 1 : dp[i][j];
        dp[i + 1][nj] = added;
        if (nj == S) {
          ans += added * (N - i);
        }
      }
    }
  }
  cout << ans << endl;
}
