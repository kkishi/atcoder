#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<string> s(8);
  cin >> s;
  rep(i, 8) rep(j, 8) if (s[i][j] == '*') {
    string ans = "a1";
    ans[0] += j;
    ans[1] += 7 - i;
    wt(ans);
  }
}
