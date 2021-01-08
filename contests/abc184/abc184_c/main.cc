#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r1, c1, r2, c2);
  int r = abs(r1 - r2);
  int c = abs(c1 - c2);
  if (r > c) swap(r, c);
  int ans = div_ceil(r + c, 3);
  chmin(ans, div_ceil(c - r, 3) + 1);
  if (even(r + c)) {
    chmin(ans, 2);
  } else {
    chmin(ans, 3);
  }
  wt(ans);
}
