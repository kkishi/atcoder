#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"

using S = int;

S op(S a, S b) { return min(a, b); }

S e() { return numeric_limits<int>::max(); }

using F = int;

S mapping(F f, S x) { return x - f; }

F composition(F f, F g) { return f + g; }

F id() { return 0; }

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;

  int sep = (n + 1) / 2;
  auto idx = [&sep](int i) { return (i % 2 == 0 ? 0 : sep) + i / 2; };

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  rep(i, n) seg.set(idx(i), c[i]);

  int ans = 0;
  ints(q);
  rep(q) {
    ints(k);
    int begin, end;
    if (k == 1) {
      ints(x);
      x = idx(x - 1);
      begin = x, end = x + 1;
    } else if (k == 2) {
      begin = 0, end = sep;
    } else {
      begin = 0, end = n;
    }
    ints(a);
    if (seg.prod(begin, end) < a) continue;
    seg.apply(begin, end, a);
    ans += (end - begin) * a;
  }
  wt(ans);
}
