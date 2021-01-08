#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> v;
  rep(i, 4) if (hasbit(n, i)) v.pb(1 << i);
  wt(sz(v));
  for (int vi : v) wt(vi);
}
