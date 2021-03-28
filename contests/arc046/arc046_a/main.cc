#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int d = div_ceil(n, 9);
  int r = n - (d - 1) * 9;
  int ans = 0;
  rep(d)(ans *= 10) += r;
  wt(ans);
}
