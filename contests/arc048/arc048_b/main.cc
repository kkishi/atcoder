#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"

void Main() {
  ints(n);
  V<int> r(n), h(n);
  rep(i, n) cin >> r[i] >> h[i];
  each(e, h)-- e;
  BIT<int> bit(100001);
  rep(i, n) bit.Add(r[i], 1);
  map<int, map<int, int>> m;
  rep(i, n)++ m[r[i]][h[i]];
  rep(i, n) {
    int lt = bit.Sum(r[i] - 1);
    int gt = n - bit.Sum(r[i]);
    int eq_w = m[r[i]][(h[i] + 1) % 3];
    int eq_d = m[r[i]][h[i]] - 1;
    int eq_l = m[r[i]][(h[i] + 2) % 3];
    wt(lt + eq_w, gt + eq_l, eq_d);
  }
}
