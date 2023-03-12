#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, x, m);
  int ans = 0;
  int p = 1;
  rep(x) {
    ans += p;
    ans %= m;
    p *= a;
    p %= m;
  }
  wt(ans);
}
