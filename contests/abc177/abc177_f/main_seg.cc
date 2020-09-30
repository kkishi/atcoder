#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"
#include "modint.h"

const int inf = numeric_limits<int>::max() / 10;

struct S {
  int l, m;
};

S op(S a, S b) { return {min(a.l, b.l), min(a.m, b.m)}; }

S e() { return {inf, inf}; }

using F = optional<int>;

S mapping(F f, S x) {
  if (!f) return x;
  return {x.l, x.l + *f};
}

F composition(F f, F g) { return f ? f : g; }

F id() { return nullopt; }

void Main() {
  ints(h, w);

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> tree(w);
  rep(i, w) tree.set(i, {i, 0});

  rep(i, h) {
    ints(a, b);
    --a;
    int x;
    if (a == 0) {
      x = inf;
    } else {
      x = tree.prod(a - 1, a).m;
      if (x != inf) x -= a - 1;
    }
    tree.apply(a, b, x);
    int ans = tree.prod(0, w).m;
    if (ans == inf) {
      wt(-1);
    } else {
      wt(ans + i + 1);
    }
  }
}
