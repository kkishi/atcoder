#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, a, d, n);
  int b = a + d * (n - 1);
  int mi = min(a, b);
  int ma = max(a, b);
  if (x < mi) {
    wt(mi - x);
  } else if (ma < x) {
    wt(x - ma);
  } else {
    if (d == 0) {
      wt(abs(a - x));
    } else {
      d = abs(d);
      int c = div_ceil(x - mi, d);
      wt(min(c * d + mi - x, x - ((c - 1) * d + mi)));
    }
  }
}
