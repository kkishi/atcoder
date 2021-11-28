#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, C, q);
  V<int> t(q), n(q), c(q);
  rep(i, q) {
    cin >> t[i] >> n[i] >> c[i];
    --n[i], --c[i];
  }
  set<int> rs, cs;
  V<int> ans(C);
  rrep(i, q) {
    if (t[i] == 1) {
      if (rs.count(n[i]) == 0) {
        ans[c[i]] += w - sz(cs);
      }
      rs.insert(n[i]);
    } else {
      if (cs.count(n[i]) == 0) {
        ans[c[i]] += h - sz(rs);
      }
      cs.insert(n[i]);
    }
  }
  wt(ans);
}
