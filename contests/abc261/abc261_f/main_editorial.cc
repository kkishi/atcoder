#include <bits/stdc++.h>

#include "atcoder.h"
#include "inversion_number.h"

void Main() {
  ints(n);
  V<int> c(n), x(n);
  cin >> c >> x;
  V<int> all_idx;
  VV<int> idx(n);
  rep(i, n) {
    all_idx.pb(x[i]);
    idx[c[i] - 1].pb(x[i]);
  }
  int ans = InversionNumber(all_idx);
  each(e, idx) ans -= InversionNumber(e);
  wt(ans);
}
