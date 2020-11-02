#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 100;
  rep(n) {
    ints(t);
    chmin(ans, t);
  }
  wt(ans);
}
