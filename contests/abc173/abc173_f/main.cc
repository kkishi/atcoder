#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rrep(i, n) ans += (i + 1) * (n - i);
  rep(i, n - 1) {
    ints(u, v);
    if (u > v) swap(u, v);
    ans -= u * (n - (v - 1));
  }
  wt(ans);
}
