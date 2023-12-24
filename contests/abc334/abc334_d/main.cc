#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> r(n);
  cin >> r;
  sort(r);
  rep(i, 1, sz(r)) r[i] += r[i - 1];
  rep(q) {
    ints(x);
    wt(lower_bound(all(r), x + 1) - r.begin());
  }
}
