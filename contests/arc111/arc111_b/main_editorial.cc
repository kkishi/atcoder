#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n);
  V<pair<int, int>> v(n);
  cin >> v;
  each(a, b, v)-- a, --b;
  int m = 400000;
  DisjointSet ds(m);
  each(a, b, v) ds.Union(a, b);
  map<int, int> cnt;
  each(a, _, v)++ cnt[ds.Find(a)];
  int ans = 0;
  each(k, v, cnt) ans += min(v, ds.Size(k));
  wt(ans);
}
