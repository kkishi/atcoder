#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  int ans = k;
  rep(i, n - 1) ans *= k - 1;
  wt(ans);
}
