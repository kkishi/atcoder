#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

struct S {
  mint val;
  int len;
};

S op(S a, S b) { return {a.val + b.val, a.len + b.len}; }

S e() { return {0, 0}; }

struct F {
  mint b, c;
};

S mapping(F f, S x) { return {f.b * x.val + f.c * x.len, x.len}; }

F composition(F f, F g) { return {f.b * g.b, f.b * g.c + f.c}; }

F id() { return {1, 0}; }

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  rep(i, n) seg.set(i, {a[i], 1});

  rep(q) {
    ints(k);
    if (k == 0) {
      ints(l, r, b, c);
      seg.apply(l, r, {b, c});
    } else {
      ints(l, r);
      wt(seg.prod(l, r).val);
    }
  }
}
