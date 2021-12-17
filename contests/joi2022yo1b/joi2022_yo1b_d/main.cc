#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  each(e, a)++ m[e];
  int ma = big;
  int ans;
  each(k, v, m) if (chmin(ma, v)) ans = k;
  wt(ans);
}
