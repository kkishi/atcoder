#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(n) {
    ints(l, r);
    ans += r - l + 1;
  }
  wt(ans);
}
