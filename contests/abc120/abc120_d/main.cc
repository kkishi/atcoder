#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  vector<int> a(m), b(m);
  rep(i, m) cin >> a[i] >> b[i];
  vector<int> ans(m);
  DisjointSet ds(n + 1);
  int sum = n * (n - 1) / 2;
  rrep(i, m) {
    ans[i] = sum;
    if (!ds.Same(a[i], b[i])) {
      dbg(ds.Size(a[i]), ds.Size(b[i]));
      sum -= ds.Size(a[i]) * ds.Size(b[i]);
      ds.Union(a[i], b[i]);
    }
  }
  rep(i, m) wt(ans[i]);
}
