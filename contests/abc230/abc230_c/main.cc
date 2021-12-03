#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b, p, q, r, s);
  int h = q - p + 1;
  int w = s - r + 1;
  vector ans(h, string(w, '.'));
  rep(i, p, q + 1) rep(j, r, s + 1) {
    bool black = false;
    {
      int l = max(1 - a, 1 - b);
      int lx = a + l;
      int ly = b + l;
      int r = min(n - a, n - b);
      int rx = a + r;
      int ry = b + r;
      if (lx <= i && i <= rx && ly <= j && j <= ry && (i - lx) == (j - ly)) {
        black = true;
      }
    }
    {
      int l = max(1 - a, b - n);
      int lx = a + l;
      int ly = b - l;
      int r = min(n - a, b - 1);
      int rx = a + r;
      int ry = b - r;
      if (lx <= i && i <= rx && ry <= j && j <= ly && (i - lx) == (ly - j)) {
        black = true;
      }
    }
    if (black) {
      ans[i - p][j - r] = '#';
    }
  }
  each(e, ans) wt(e);
}
