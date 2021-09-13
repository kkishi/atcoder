#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  Compressor cx(x), cy(y);
  rep(i, n) x[i] = cx(x[i]), y[i] = cy(y[i]);
  vector seen(n, vector(n, false));
  rep(i, n) seen[x[i]][y[i]] = true;
  int ans = 0;
  rep(i, n) rep(j, i + 1, n) {
    if (x[i] == x[j] || y[i] == y[j]) continue;
    if (seen[x[i]][y[j]] && seen[x[j]][y[i]]) ++ans;
  }
  wt(ans / 2);
}
