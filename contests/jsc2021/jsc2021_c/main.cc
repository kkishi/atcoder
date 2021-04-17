#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  int ans = -big;
  rep(g, 1, 200001) {
    int x = div_ceil(a, g) * g;
    int y = x + g;
    if (a <= x && y <= b) chmax(ans, g);
  }
  wt(ans);
}
