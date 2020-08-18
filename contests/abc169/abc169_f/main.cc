#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

ModInt<998244353> dp[3001][3001];
int A[3000];

int main() {
  ints(N, S);
  rep(i, N) cin >> A[i];

  dp[0][0] = 1;
  rep(i, N) {
    for (int s = 0; s <= 3000; ++s) {
      dp[i + 1][s] = dp[i][s] * 2;
    }
    for (int s = 0; s <= 3000; ++s) {
      int s2 = s + A[i];
      if (s2 <= 3000) {
        dp[i + 1][s2] += dp[i][s];
      }
    }
  }
  cout << dp[N][S] << endl;
}
