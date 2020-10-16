#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y);
  auto score = [](int x) {
    if (x == 1) return 300000;
    if (x == 2) return 200000;
    if (x == 3) return 100000;
    return 0;
  };
  wt(score(x) + score(y) + (x == 1 && y == 1 ? 400000 : 0));
}
