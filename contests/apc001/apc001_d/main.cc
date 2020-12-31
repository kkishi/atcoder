#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;

  DisjointSet ds(n);
  rep(m) {
    ints(x, y);
    ds.Union(x, y);
  }

  multiset<int> as;
  map<int, int> reps;
  rep(i, n) {
    as.insert(a[i]);
    auto [it, ok] = reps.insert({ds.Find(i), a[i]});
    if (!ok) chmin(it->second, a[i]);
  }

  int x = (sz(reps) - 1) * 2;
  if (x > n) {
    wt("Impossible");
    return;
  }

  V<int> vs;
  for (auto [_, v] : reps) {
    vs.push_back(v);
    as.erase(as.find(v));
  }
  for (auto a : as) vs.push_back(a);
  wt(accumulate(vs.begin(), vs.begin() + x, int(0)));
}
