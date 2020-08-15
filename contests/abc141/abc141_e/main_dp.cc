#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int dp[5001][5001];

int main() {
  rd(int, n);
  rd(string, s);
  int ans = 0;
  rrep(i, n) rrep(j, n) if (s[i] == s[j]) {
    dp[i][j] = dp[i + 1][j + 1] + 1;
    chmax(ans, min(abs(i - j), dp[i][j]));
  }
  wt(ans);
}
