#include <bits/stdc++.h>

#include <atcoder/twosat>

#include "atcoder.h"

void Main() {
  ints(n, d);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  atcoder::two_sat ts(n);
  rep(i, n - 1) rep(j, i + 1, n) {
    if (abs(x[i] - x[j]) < d) ts.add_clause(i, false, j, false);
    if (abs(x[i] - y[j]) < d) ts.add_clause(i, false, j, true);
    if (abs(y[i] - x[j]) < d) ts.add_clause(i, true, j, false);
    if (abs(y[i] - y[j]) < d) ts.add_clause(i, true, j, true);
  }

  bool ok = ts.satisfiable();
  wt(ok);
  if (ok) {
    V<bool> ans = ts.answer();
    rep(i, n) wt((ans[i] ? x : y)[i]);
  }
}
