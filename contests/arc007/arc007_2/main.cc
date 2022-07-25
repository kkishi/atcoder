#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> v(n);
  rep(i, n) v[i] = i + 1;
  V<int> rv(n + 1);
  rep(i, n) rv[i + 1] = i;
  int x = 0;
  rep(m) {
    ints(d);
    if (d == x) continue;
    int i = rv[d];
    rv[x] = i;
    swap(x, v[i]);
  }
  each(e, v) wt(e);
}
