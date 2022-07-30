#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(h, w);
  vector B(h, vector(w, 0));
  vector W(h, vector(w, 0));
  rep(i, h) rep(j, w) {
    ints(c);
    (even(i + j) ? B : W)[i][j] = c;
  }
  CumulativeSum2D sb(B), sw(W);
  int ans = 0;
  rep(i, h) rep(j, w) rep(k, i, h) rep(l, j, w) {
    if (sb.Get(i, j, k, l) == sw.Get(i, j, k, l))
      chmax(ans, (k - i + 1) * (l - j + 1));
  }
  wt(ans);
}
