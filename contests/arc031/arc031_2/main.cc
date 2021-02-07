#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  V<string> a(10);
  cin >> a;
  bool ok = false;
  rep(i, 10) rep(j, 10) if (a[i][j] == 'x') {
    a[i][j] = 'o';
    DisjointSet ds(100);
    auto idx = [](int r, int c) { return r * 10 + c; };
    rep(k, 10) rep(l, 10) if (a[k][l] == 'o') {
      if (k + 1 < 10 && a[k + 1][l] == 'o') ds.Union(idx(k, l), idx(k + 1, l));
      if (l + 1 < 10 && a[k][l + 1] == 'o') ds.Union(idx(k, l), idx(k, l + 1));
    }
    set<int> s;
    rep(k, 10) rep(l, 10) if (a[k][l] == 'o') s.insert(ds.Find(idx(k, l)));
    if (sz(s) == 1) ok = true;
    a[i][j] = 'x';
  }
  wt(ok ? "YES" : "NO");
}
