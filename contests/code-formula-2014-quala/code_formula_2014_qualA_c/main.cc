#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector<tuple<int, int, int>> v;
  set<int> decided;
  rep(i, n) {
    rep(j, k) {
      ints(a);
      v.emplace_back(j, i, a);
    }
    sort(v);
    set<int> seen;
    set<int> s;
    for (auto [J, I, idx] : v) {
      int better = sz(seen);
      if (!seen.insert(idx).second) continue;
      if (decided.count(idx)) continue;
      if (better + (n - 1 - i) * J < k) s.insert(idx);
    }
    wt(s);
    decided.merge(s);
  }
}
