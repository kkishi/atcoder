#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "i128.h"

void Main() {
  strings(x);
  ints(m);
  if (sz(x) == 1) {
    wt((x[0] - '0') <= m ? 1 : 0);
    return;
  }
  auto f = [&](i128 base) {
    i128 val = 0;
    rep(i, sz(x)) {
      val = val * base + (x[i] - '0');
      if (val > m) return false;
    }
    return true;
  };
  i128 d = *max_element(all(x)) - '0';
  if (!f(d + 1)) {
    wt(0);
    return;
  }
  wt(BinarySearch<i128>(d + 1, 4000'000'000'000'000'000LL, f) - d);
}
