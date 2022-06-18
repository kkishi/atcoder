#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h1, h2, h3, w1, w2, w3);
  int ans = 0;
  rep(a, 1, 31) rep(b, 1, 31) rep(d, 1, 31) rep(e, 1, 31) {
    int c = h1 - a - b;
    int f = h2 - d - e;
    int g = w1 - a - d;
    int h = w2 - b - e;
    int i1 = h3 - g - h;
    int i2 = w3 - c - f;
    if (1 <= min({c, f, g, h, i1, i2}) && i1 == i2) ++ans;
  }
  wt(ans);
}
