#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector c(n, vector(n, int(0)));
  cin >> c;

  bool ok = true;

  // v = {a, b}
  VV<int> v;
  rep(2) {
    vector nc(n, vector(n, int(0)));
    rep(i, n) rep(j, n) nc[j][i] = c[i][j];
    swap(c, nc);

    V<int> a(n);
    int lo = *min_element(all(c[0]));
    rep(i, n) a[i] = c[0][i] - lo;
    rep(i, 1, n) {
      int lo = *min_element(all(c[i]));
      rep(j, n) if (c[i][j] - lo != a[j]) ok = false;
    }
    v.eb(a);
  }

  int x = c[0][0] - (v[0][0] + v[1][0]);
  each(e, v[1]) e += x;
  rep(i, n) rep(j, n) if (c[i][j] != v[0][i] + v[1][j]) ok = false;

  wt(ok);
  if (ok) each(e, v) wt(e);
}
