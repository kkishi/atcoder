#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(i, o, t, j, l, s, z);
  auto f = [](int x) -> int { return x - (x & 1); };
  int ans = f(i) + o + f(j) + f(l);
  if (i > 0 && j > 0 && l > 0) {
    chmax(ans, 3 + f(i - 1) + o + f(j - 1) + f(l - 1));
  }
  wt(ans);
}
