#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = big;
  rep(n) {
    ints(a, p, x);
    if (x > a) {
      chmin(ans, p);
    }
  }
  if (ans == big) ans = -1;
  wt(ans);
}
