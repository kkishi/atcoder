#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  int ans = 0;
  rep(i, n) {
    ints(h);
    if (h >= k) ++ans;
  }
  wt(ans);
}
