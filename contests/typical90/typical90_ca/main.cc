#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector v(h, vector(w, int(0)));
  rep(r, h) rep(c, w) {
    ints(a);
    v[r][c] -= a;
  }
  rep(r, h) rep(c, w) {
    ints(b);
    v[r][c] += b;
  }
  int ans = 0;
  rep(r, h - 1) rep(c, w - 1) {
    int d = v[r][c];
    ans += abs(d);
    rep(i, 2) rep(j, 2) v[r + i][c + j] -= d;
  }
  if (v[h - 1][w - 1] == 0) {
    wt("Yes");
    wt(ans);
  } else {
    wt("No");
  }
}
