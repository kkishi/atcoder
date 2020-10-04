#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(m, d);
  int ans = 0;
  rep(i, 1, m + 1) rep(j, 1, d + 1) {
    int d1 = j % 10;
    int d10 = j / 10;
    if (d1 >= 2 && d10 >= 2 && d1 * d10 == i) ++ans;
  }
  wt(ans);
}
