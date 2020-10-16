#include <bits/stdc++.h>

#include "atcoder.h"

int dp[4000][3];

int toInt(int c) { return string("RGB").find(c); }

int rem(char a, char b) {
  string s = "RGB";
  rep(i, 3) if (s[i] != a && s[i] != b) return i;
}

void Main() {
  ints(N);
  strings(S);

  rrep(i, N) {
    int c = toInt(S[i]);
    rep(j, 3) dp[i][j] = (i == N - 1 ? 0 : dp[i + 1][j]) + (c == j ? 1 : 0);
  }
  long long ans = 0;
  rep(i, N) {
    rep(j, i + 1, N - 1) {
      if (S[i] == S[j]) {
        continue;
      }
      int c = rem(S[i], S[j]);
      int cnt = dp[j + 1][c];
      int k = j + (j - i);
      if (k < N && toInt(S[k]) == c) {
        --cnt;
      }
      ans += cnt;
    }
  }
  wt(ans);
}
