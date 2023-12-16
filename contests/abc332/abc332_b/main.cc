#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k, G, M);
  int g = 0, m = 0;
  rep(k) {
    if (g == G) {
      g = 0;
    } else if (m == 0) {
      m = M;
    } else {
      int x = min(m, G - g);
      g += x;
      m -= x;
    }
  }
  wt(g, m);
}
