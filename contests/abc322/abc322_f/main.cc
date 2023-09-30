#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"

struct S {
  int l;       // Length of the substring.
  int lv, rv;  // Values of each end (0 or 1).
  int ll, rl;  // Lengths of the contiguous values on each end (0s or 1s).
  int l0, l1;  // Maximum lengths of 0s and 1s in the substring.
};

S op(S a, S b) {
  if (a.l == -1) return b;
  if (b.l == -1) return a;
  S c;
  c.l = a.l + b.l;
  c.lv = a.lv;
  c.rv = b.rv;
  c.ll = a.ll;
  c.rl = b.rl;
  c.l0 = max(a.l0, b.l0);
  c.l1 = max(a.l1, b.l1);
  if (a.rv == b.lv) {
    int len = a.rl + b.ll;
    if (a.rv == 0) chmax(c.l0, len);
    if (a.rv == 1) chmax(c.l1, len);
    if (a.l == a.rl) c.ll += b.ll;
    if (b.l == b.ll) c.rl += a.rl;
  }
  return c;
};

S e() { return S{-1, -1, -1, -1, -1, -1, -1}; };

using F = int;

S mapping(F f, S x) {
  if (f) {
    x.lv ^= 1;
    x.rv ^= 1;
    swap(x.l0, x.l1);
  }
  return x;
}

F composition(F f, F g) { return f ^ g; };

F id() { return 0; }

void Main() {
  ints(n, q);
  strings(s);
  V<S> v(n);
  rep(i, n) {
    int x = s[i] - '0';
    v[i] = S{1, x, x, 1, 1, !x, x};
  }
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> t(v);
  rep(q) {
    ints(c, l, r);
    --l;
    if (c == 1) {
      t.apply(l, r, 1);
    } else {
      wt(t.prod(l, r).l1);
    }
  }
}
