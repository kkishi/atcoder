#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"

struct S {
  int ones;
  int zeros;
  int inversions;
};

S op(S a, S b) {
  return {a.ones + b.ones, a.zeros + b.zeros,
          a.inversions + b.inversions + a.ones * b.zeros};
}

S e() { return {0, 0, 0}; }

using F = bool;

S mapping(F f, S x) {
  if (!f) return x;
  return {x.zeros, x.ones, x.zeros * x.ones - x.inversions};
}

F composition(F f, F g) { return f ^ g; }

F id() { return false; }

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  rep(i, n) seg.set(i, {a[i], 1 - a[i], 0});

  rep(q) {
    ints(t, l, r);
    if (t == 1) {
      seg.apply(l - 1, r, true);
    } else {
      wt(seg.prod(l - 1, r).inversions);
    }
  }
}
