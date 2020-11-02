#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, h, w);
  int ans = 0;
  rep(n) {
    ints(a, b);
    if (a >= h && b >= w) ++ans;
  }
  wt(ans);
}
