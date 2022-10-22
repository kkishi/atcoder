#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> c(h);
  cin >> c;
  V<int> ans;
  rep(i, w) {
    int sum = 0;
    rep(j, h) if (c[j][i] == '#')++ sum;
    ans.eb(sum);
  }
  wt(ans);
}
