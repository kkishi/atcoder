#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  using P = pair<int, int>;
  V<P> v;
  rep(n) {
    ints(a, b);
    v.eb(a, 1);
    v.eb(a + b, -1);
  }
  sort(v);
  V<int> ans(n);
  int cnt = 0;
  rep(i, sz(v)) {
    if (i > 0) {
      int d = v[i].first - v[i - 1].first;
      if (d > 0) {
        if (cnt > 0) {
          ans[cnt - 1] += d;
        }
      }
    }
    auto [_, x] = v[i];
    cnt += x;
  }
  wt(ans);
}
