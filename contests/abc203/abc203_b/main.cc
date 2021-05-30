#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  int ans = 0;
  rep(i, n) rep(j, k) { ans += (i + 1) * 100 + (j + 1); }
  wt(ans);
}
