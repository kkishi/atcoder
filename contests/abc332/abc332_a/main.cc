#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, s, k);
  int ans = 0;
  rep(n) {
    ints(p, q);
    ans += p * q;
  }
  if (ans < s) ans += k;
  wt(ans);
}
