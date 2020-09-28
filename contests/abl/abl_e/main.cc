#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

struct S {
  mint val;
  int len;
};

S op(S a, S b) { return {a.val * mint(10).Pow(b.len) + b.val, a.len + b.len}; }

S e() { return {0, 0}; }

using F = int;

VV<mint> seq(10);

S mapping(F f, S x) {
  if (f == -1) return x;
  return {seq[f][x.len], x.len};
}

F composition(F f, F g) {
  if (f == -1) return g;
  if (g == -1) return f;
  return f;
}

F id() { return -1; }

void Main() {
  ints(n, q);

  rep(i, 10) {
    V<mint> v(n + 1);
    rep(j, n) v[j + 1] = v[j] * 10 + i;
    seq[i] = v;
  }

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> tree(n);
  rep(i, n) tree.set(i, {1, 1});
  rep(q) {
    ints(l, r, d);
    tree.apply(l - 1, r, d);
    wt(tree.prod(0, n).val);
  }
}
