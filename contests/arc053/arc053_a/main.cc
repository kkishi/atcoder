#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  int ans = 0;
  rep(i, h) rep(j, w) {
    if (i + 1 < h) ++ans;
    if (j + 1 < w) ++ans;
  }
  wt(ans);
}
