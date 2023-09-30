#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"

struct S {
  int li, ri;
  int lv, rv;
  int ll, rl;
  int l0, l1;
  int len() const { return ri - li + 1; };
};

S E = S{-1, -1, -1, -1, -1, -1, -1, -1};

S op(S a, S b) {
  if (a.li == -1) return b;
  if (b.li == -1) return a;
  S c;
  c.li = a.li;
  c.ri = b.ri;
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
    if (a.len() == a.rl) c.ll += b.ll;
    if (b.len() == b.ll) c.rl += a.rl;
  }
  return c;
};

S e() { return E; };

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
    int x = s[i] == '1';
    v[i] = S{i, i, x, x, 1, 1, (x == 0), (x == 1)};
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
