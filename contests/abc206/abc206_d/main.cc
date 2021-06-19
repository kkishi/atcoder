#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  DisjointSet ds(200001);
  int ans = 0;
  rep(i, n) {
    int j = n - 1 - i;
    if (!ds.Same(a[i], a[j])) {
      ds.Union(a[i], a[j]);
      ++ans;
    }
  }
  wt(ans);
}
