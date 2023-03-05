#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "atcoder.h"
#include "bit.h"

bool g(add_min::S x) { return x > 0; }

void Main() {
  ints(n, b, q);
  V<int> a(n);
  cin >> a;
  V<int> s = a;
  rep(i, 1, n) s[i] += s[i - 1];
  V<int> v(n);
  rep(i, n) v[i] = b * (i + 1) - s[i];
  add_min::segtree t(v);
  BIT<int> bit(n);
  rep(i, n) bit.Set(i, a[i]);
  rep(q) {
    ints(c, x);
    --c;
    t.apply(c, n, a[c]);
    a[c] = x;
    bit.Set(c, x);
    t.apply(c, n, -a[c]);
    int r = t.max_right<g>(0);
    chmin(r, n - 1);
    wt((double)bit.Sum(r) / (r + 1));
  }
}
