#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, q);
  V<int> c(n);
  cin >> c;
  V<map<int, int>> ms(n);
  rep(i, n)++ ms[i][c[i]];
  DisjointSet ds(n);
  rep(q) {
    ints(k);
    if (k == 1) {
      ints(a, b);
      --a, --b;
      a = ds.Find(a);
      b = ds.Find(b);
      if (a == b) continue;
      ds.Union(a, b);
      int c = ds.Find(a);
      int d = a + b - c;
      for (auto [k, v] : ms[d]) ms[c][k] += v;
    } else {
      ints(x, y);
      --x;
      wt(ms[ds.Find(x)][y]);
    }
  }
}
