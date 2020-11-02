#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, k);
  int m = max({a, b, c});
  int ans = a + b + c - m;
  rep(i, k) m *= 2;
  wt(ans + m);
}
