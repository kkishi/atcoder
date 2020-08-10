#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int dp[5001][5001];

int main() {
  rd(int, n);
  rd(string, s);
  int ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (s[i] == s[j]) {
        dp[i][j] = dp[i + 1][j + 1] + 1;
        ans = max(ans, min(abs(i - j), dp[i][j]));
      }
    }
  }
  wt(ans);
}
