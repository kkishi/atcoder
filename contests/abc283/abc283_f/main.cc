#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  V<int> ans;
  rep(i, n) {
    int mi = big;
    rep(j, i + 1, n) {
      chmin(mi, abs(p[i] - p[j]) + j - i);
      if (j - i >= mi) break;
    }
    rrep(j, i) {
      chmin(mi, abs(p[i] - p[j]) + i - j);
      if (i - j >= mi) break;
    }
    ans.pb(mi);
  }
  wt(ans);
}
