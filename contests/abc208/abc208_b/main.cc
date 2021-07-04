#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(p);
  V<int> fact(11);
  fact[0] = 1;
  rep(i, 1, 11) fact[i] = fact[i - 1] * i;
  int ans = 0;
  rrep(i, 1, 11) {
    ans += p / fact[i];
    p %= fact[i];
  }
  wt(ans);
}
