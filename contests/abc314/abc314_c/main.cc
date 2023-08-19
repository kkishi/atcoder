#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  strings(s);
  V<int> c(n);
  cin >> c;
  VV<int> idx(m);
  rep(i, n) idx[c[i] - 1].eb(i);
  rep(i, m) {
    const V<int>& v = idx[i];
    rrep(i, 1, sz(v)) swap(s[v[i]], s[v[(i + 1) % sz(v)]]);
  }
  wt(s);
}
