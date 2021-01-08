#include <bits/stdc++.h>

#include "atcoder.h"

int f(int h, int w) {
  int ans = big;
  rep(x, 1, w) {
    int a = h * x;
    int b = (w - x) * (h / 2);
    int c = (w - x) * (h - h / 2);
    chmin(ans, max({a, b, c}) - min({a, b, c}));
  }
  return min(h % 3 == 0 ? 0 : w, ans);
}

void Main() {
  ints(h, w);
  wt(min(f(h, w), f(w, h)));
}
