#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  int ans = 0;
  rep(a, 1, k + 1) {
    int l = k / a;
    rep(b, 1, l + 1) {
      int m = l / b;
      ans += m;
    }
  }
  wt(ans);
}
