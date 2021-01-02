#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> hs(100001);
  rep(i, n) {
    ints(h);
    hs[h].pb(i);
  }
  set<int> s{-1, n};
  V<int> ans(n);
  rrep(h, 100001) {
    for (int i : hs[h]) {
      auto [it, _] = s.insert(i);
      ans[i] = (i - *prev(it) - 1) + (*next(it) - i - 1);
      s.erase(it);
    }
    for (int i : hs[h]) s.insert(i);
  }
  rep(i, n) wt(ans[i]);
}
