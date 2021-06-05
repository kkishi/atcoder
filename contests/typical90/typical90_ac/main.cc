#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"

using S = int;

S op(S a, S b) { return max(a, b); }

S e() { return 0; };

using F = int;

S mapping(F f, S x) { return max(f, x); }

F composition(F f, F g) { return max(f, g); }

F id() { return 0; }

void Main() {
  ints(w, n);
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(w);
  rep(n) {
    ints(l, r);
    --l;
    int p = seg.prod(l, r);
    wt(p + 1);
    seg.apply(l, r, p + 1);
  }
}
