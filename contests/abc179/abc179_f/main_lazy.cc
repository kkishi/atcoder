#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"

using S = int;

S op(S a, S b) { return min(a, b); }

int E;

S e() { return E; }

using F = int;

S mapping(F f, S x) { return min(f, x); }

F composition(F f, F g) { return min(f, g); }

F id() { return E; }

void Main() {
  ints(n, q);
  E = n - 2;

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> r(n), c(n);

  int ans = (n - 2) * (n - 2);
  rep(q) {
    ints(a, b);
    if (b == 1) continue;
    if (a == 1) {
      int x = r.get(b - 1);
      ans -= x;
      c.apply(1, x + 1, b - 2);
    } else {
      int x = c.get(b - 1);
      ans -= x;
      r.apply(1, x + 1, b - 2);
    }
  }
  wt(ans);
}
