#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(p, a, b, s, g);
    rep(i, p) {
      if (s == g) {
        wt(i);
        goto next;
      }
      s *= a;
      s += b;
      s %= p;
    }
    wt(-1);
  next:
    continue;
  }
}
