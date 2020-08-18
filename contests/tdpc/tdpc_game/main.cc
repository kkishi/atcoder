#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(A, B);
  vector<int> a(A), b(B);
  cin >> a >> b;
  reverse(all(a));
  reverse(all(b));
  vector<int> as(A + 1), bs(B + 1);
  rep(i, A) as[i + 1] = as[i] + a[i];
  rep(i, B) bs[i + 1] = bs[i] + b[i];
  vector dp(A + 1, vector(B + 1, 0));
  rep(i, A + 1) rep(j, B + 1) {
    if (i > 0) chmax(dp[i][j], as[i] + bs[j] - dp[i - 1][j]);
    if (j > 0) chmax(dp[i][j], as[i] + bs[j] - dp[i][j - 1]);
  }
  wt(dp[A][B]);
}
