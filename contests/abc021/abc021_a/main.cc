#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> v;
  rep(i, 4) if ((n >> i) & 1) v.push_back(1 << i);
  wt(sz(v));
  for (int vi : v) wt(vi);
}
