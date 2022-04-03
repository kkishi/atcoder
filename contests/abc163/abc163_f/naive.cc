#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  each(e, c)-- e;
  V<int> cnt(n);
  each(e, c)++ cnt[e];
  V<pair<int, int>> es;
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    es.eb(a, b);
  }
  rep(i, n) {
    DisjointSet ds(n);
    each(a, b, es) if (c[a] != i && c[b] != i) ds.Union(a, b);
    map<int, int> m;
    rep(j, n) if (c[j] != i) m[ds.Find(j)] = ds.Size(j);
    int ans = n * (n - 1) / 2 + n;
    each(_, e, m) ans -= e * (e - 1) / 2 + e;
    wt(ans);
  }
}
