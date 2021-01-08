#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> p(n);
  cin >> p;
  set<V<int>> s;
  rep(i, n - k + 1) {
    V<int> q = p;
    sort(q.begin() + i, q.begin() + i + k);
    dbg(i, q);
    s.insert(q);
  }
  wt(s.size());
  for (auto& v : s) dbg(v);
}
