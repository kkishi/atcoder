#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> v(n);
  V<int> idx(n);
  rep(i, n) v[i] = idx[i] = i;
  rep(q) {
    ints(x);
    --x;
    int i = idx[x];
    int j = (i == n - 1 ? i - 1 : i + 1);
    int y = v[j];
    swap(v[i], v[j]);
    swap(idx[x], idx[y]);
  }
  each(e, v)++ e;
  wt(v);
}
