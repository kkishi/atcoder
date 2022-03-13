#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<double> v(n);
  cin >> v;
  sort(v);
  double ans = (v[0] + v[1]) / 2;
  rep(i, 2, n) ans = (ans + v[i]) / 2;
  wt(ans);
}
