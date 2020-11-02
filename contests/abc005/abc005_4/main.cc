#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> d(n, V<int>(n));
  cin >> d;

  VV<int> s(n + 1, V<int>(n + 1));
  rep(i, n) rep(j, n) s[i + 1][j + 1] =
      s[i][j + 1] + s[i + 1][j] - s[i][j] + d[i][j];

  V<int> maxi(n * n + 1);
  rep(i, 1, n + 1) rep(j, 1, n + 1) rep(k, i) rep(l, j) {
    chmax(maxi[(i - k) * (j - l)], s[i][j] - s[k][j] - s[i][l] + s[k][l]);
  }
  rep(i, n * n) chmax(maxi[i + 1], maxi[i]);

  ints(q);
  rep(q) {
    ints(p);
    wt(maxi[p]);
  }
}
