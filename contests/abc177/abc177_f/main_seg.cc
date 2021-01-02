#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"
#include "modint.h"

struct S {
  int l, m;
};

S op(S a, S b) { return {min(a.l, b.l), min(a.m, b.m)}; }

S e() { return {big, big}; }

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
      x = big;
    } else {
      x = tree.prod(a - 1, a).m;
      if (x != big) x -= a - 1;
    }
    tree.apply(a, b, x);
    int ans = tree.prod(0, w).m;
    if (ans == big) {
      wt(-1);
    } else {
      wt(ans + i + 1);
    }
  }
}
