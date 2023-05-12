#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> C(h);
  cin >> C;
  int n = min(h, w);
  V<int> ans(n);
  rep(i, h) rep(j, w) if (C[i][j] == '#') {
    int s = 1;
    bool ok = true;
    while (true) {
      V<int> r = {i - s, i - s, i + s, i + s};
      V<int> c = {j + s, j - s, j - s, j + s};
      int cnt = 0;
      rep(i, 4) if (inside(r[i], c[i], h, w) && C[r[i]][c[i]] == '#')++ cnt;
      if (cnt == 4) {
        ++s;
      } else {
        if (cnt != 0) ok = false;
        break;
      }
    }
    if (ok) ++ans[s - 2];
  }
  wt(ans);
}
