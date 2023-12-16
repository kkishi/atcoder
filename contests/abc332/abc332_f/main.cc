#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

namespace affine {
using S = mint;
S op(S a, S b) { return a + b; }
S e() { return 0; }
struct F {
  S a, b;
};
S mapping(F f, S x) { return f.a * x + f.b; }
F composition(F f, F g) { return F{f.a * g.a, f.a * g.b + f.b}; }
F id() { return F{1, 0}; }
using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
}  // namespace affine

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  affine::segtree t(n);
  rep(i, n) t.set(i, a[i]);
  rep(m) {
    ints(l, r, x);
    --l;
    mint w = r - l;
    t.apply(l, r, affine::F{(w - 1) / w, x / w});
  }
  V<mint> ans;
  rep(i, n) ans.eb(t.get(i));
  wt(ans);
}
