#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 4;
  wt(n);
  Rand r;
  V<string> a(4, string(4, '0'));
  rep(i, 10) {
    int u = r.Int(0, n - 1);
    int v = r.Int(0, n - 1);
    if (u > v) swap(u, v);
    if (u == v) {
      --i;
      continue;
    }
    a[u][v] = '1';
    a[v][u] = '1';
  }
  each(e, a) wt(e);
}
