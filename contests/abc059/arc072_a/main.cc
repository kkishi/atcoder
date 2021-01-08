#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = big;
  rep(i, 2) {
    int sum = 0;
    int op = 0;
    rep(j, n) {
      int nsum = sum + a[j];
      dbg(i, j, nsum);
      if (i ^ (j & 1)) {
        if (nsum <= 0) {
          op += 1 - nsum;
          nsum = 1;
        }
      } else {
        if (nsum >= 0) {
          op += nsum + 1;
          nsum = -1;
        }
      }
      sum = nsum;
    }
    chmin(ans, op);
  }
  wt(ans);
}
