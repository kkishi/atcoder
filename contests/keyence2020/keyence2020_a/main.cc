#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, n);
  int ans = h + w;
  rep(i, h + 1) rep(j, w + 1) if (h * w - (h - i) * (w - j) >= n)
      chmin(ans, i + j);
  wt(ans);
}
