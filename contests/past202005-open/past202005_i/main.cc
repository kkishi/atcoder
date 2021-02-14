#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> r(n), c(n);
  iota(all(r), int(0));
  iota(all(c), int(0));
  bool t = false;
  ints(q);
  rep(q) {
    ints(k);
    if (k == 3) {
      swap(r, c);
      t = !t;
    } else {
      ints(a, b);
      --a, --b;
      if (k == 1) {
        swap(r[a], r[b]);
      }
      if (k == 2) {
        swap(c[a], c[b]);
      }
      if (k == 4) {
        int R = r[a], C = c[b];
        if (t) {
          wt(n * C + R);
        } else {
          wt(n * R + C);
        }
      }
    }
  }
}
