#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> v;
  rep(n) {
    ints(t, l, r);
    l *= 2, r *= 2;
    if (t == 1) ++r;
    if (t == 3) ++l, ++r;
    if (t == 4) ++l;
    v.eb(l, r);
  }
  int ans = 0;
  rep(i, n - 1) rep(j, i + 1, n) {
    if (v[i].second <= v[j].first || v[j].second <= v[i].first) continue;
    ++ans;
  }
  wt(ans);
}
