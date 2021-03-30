#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> b(n);
  cin >> b;
  V<string> a(n, string(m, '0'));
  rep(i, n) rep(j, m) if (b[i][j] != '0') {
    int x = b[i][j] - '0';
    a[i + 1][j] += x;
    each(ni, nj, adjacent(i + 1, j)) b[ni][nj] -= x;
  }
  each(e, a) wt(e);
}
