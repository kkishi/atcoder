#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> v(4);
  cin >> v;
  int sum = accumulate(all(v), 0);
  bool ok = false;
  rep(i, 4) if (v[i] == sum - v[i]) ok = true;
  rep(i, 4) rep(j, i) if (v[i] + v[j] == sum - (v[i] + v[j])) ok = true;
  wt(ok);
}
