#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  int ans = 0;
  rep(i, h) rep(j, w) if (s[i][j] == '.') {
    if (j + 1 < w && s[i][j + 1] == '.') ++ans;
    if (i + 1 < h && s[i + 1][j] == '.') ++ans;
  }
  wt(ans);
}
