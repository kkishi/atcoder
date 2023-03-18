#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"

struct S {
  array<int, 3> cnt = {};
  array<array<int, 3>, 3> inv = {};
};

S op(S a, S b) {
  S c;
  rep(i, 3) c.cnt[i] = a.cnt[i] + b.cnt[i];
  rep(i, 3) rep(j, i + 1, 3) {
    c.inv[i][j] = a.cnt[j] * b.cnt[i] + a.inv[i][j] + b.inv[i][j];
  }
  return c;
}

S e() { return {{0, 0, 0}, 0}; }

using F = array<int, 3>;

S mapping(F f, S x) {
  S y;
  rep(i, 3) y.cnt[f[i]] += x.cnt[i];
  rep(i, 3) rep(j, i + 1, 3) {
    if (f[i] < f[j]) {
      y.inv[f[i]][f[j]] += x.inv[i][j];
    } else if (f[i] > f[j]) {
      y.inv[f[j]][f[i]] += x.cnt[j] * x.cnt[i] - x.inv[i][j];
    }
  }
  return y;
}

F composition(F f, F g) { return {f[g[0]], f[g[1]], f[g[2]]}; }

F id() { return {0, 1, 2}; }

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  rep(i, n) {
    array<int, 3> cnt = {};
    cnt[a[i]] = 1;
    seg.set(i, {cnt, 0});
  }
  rep(q) {
    ints(t, l, r);
    if (t == 1) {
      int ret = 0;
      each(e, seg.prod(l - 1, r).inv) each(e, e) ret += e;
      wt(ret);
    } else {
      ints(s, t, u);
      seg.apply(l - 1, r, F{s, t, u});
    }
  }
}
