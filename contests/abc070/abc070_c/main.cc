#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> t(n);
  cin >> t;
  int l = 1;
  rep(i, n) l = lcm(l, t[i]);
  wt(l);
}
