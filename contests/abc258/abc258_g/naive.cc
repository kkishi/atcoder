#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n) rep(j, i) rep(k, j) {
    if (a[i][j] == '1' && a[j][k] == '1' && a[k][i] == '1') {
      ++ans;
    }
  }
  wt(ans);
}
