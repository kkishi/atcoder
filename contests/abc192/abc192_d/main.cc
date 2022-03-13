#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "i128.h"

void Main() {
  strings(x);
  each(xi, x) xi -= '0';
  ints(m);
  if (sz(x) == 1) {
    wt(x[0] <= m ? 1 : 0);
    return;
  }
  auto f = [&](i128 base) {
    i128 val = 0;
    rep(i, sz(x)) {
      val = val * base + x[i];
      if (val > m) return false;
    }
    return true;
  };
  i128 d = max(x);
  if (!f(d + 1)) {
    wt(0);
    return;
  }
  wt(BinarySearch<i128>(d + 1, m + 1, f) - d);
}
