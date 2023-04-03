#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  int ans = big;
  // We want to test `a` within the following range: `a <= ceil(sqrt(m))`
  // Note that we can't do this: `a * a <= m`
  // because it is equivalent to: `a <= floor(sqrt(m))`
  // Instead, we can do: `(a-1) * (a-1) <= m`
  for (int a = 1; a <= n && (a - 1) * (a - 1) <= m; ++a) {
    int b = div_ceil(m, a);
    if (b <= n) chmin(ans, a * b);
  }
  if (ans == big) ans = -1;
  wt(ans);
}
