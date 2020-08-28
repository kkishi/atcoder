#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

#define int ll

int f(int h, int w) {
  int ans = numeric_limits<int>::max();
  rep(x, 1, w) {
    int a = h * x;
    int b = (w - x) * (h / 2);
    int c = (w - x) * (h - h / 2);
    chmin(ans, max({a, b, c}) - min({a, b, c}));
  }
  return min(h % 3 == 0 ? 0 : w, ans);
}

main() {
  ints(h, w);
  wt(min(f(h, w), f(w, h)));
}
