#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(x1, y1, x2, y2);
    rep(x, x1 - 5, x1 + 6) rep(y, y1 - 5, y1 + 6) {
      auto sq = [](int x) { return x * x; };
      int a = sq(x1 - x) + sq(y1 - y);
      int b = sq(x2 - x) + sq(y2 - y);
      if (a == 5 && b == 5) return true;
    }
    return false;
  }());
}
