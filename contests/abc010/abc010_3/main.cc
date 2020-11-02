#include <bits/stdc++.h>

#include "atcoder.h"
#define sq(x) ((x) * (x))

void Main() {
  ints(txa, tya, txb, tyb, t, v, n);
  rep(n) {
    ints(x, y);
    double d =
        sqrt(sq(x - txa) + sq(y - tya)) + sqrt(sq(txb - x) + sq(tyb - y));
    if (d - 1e-6 < t * v) {
      wt("YES");
      return;
    }
  }
  wt("NO");
}
