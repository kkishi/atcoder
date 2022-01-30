#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  vector b(w, vector(h, int(0)));
  rep(i, h) rep(j, w) b[j][i] = a[i][j];
  each(e, b) wt(e);
}
