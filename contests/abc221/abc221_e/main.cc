#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "atcoder.h"
#include "compressor.h"
#include "modint.h"

using mint = ModInt<998244353>;

using S = mint;
S op(S a, S b) { return a + b; }
S e() { return 0; }
using F = mint;
S mapping(F f, S x) { return f * x; }
F composition(F f, F g) { return f * g; }
F id() { return 1; }
using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  Compressor c(a);
  rep(i, n) a[i] = c(a[i]);

  int N = sz(c.coord);
  segtree s(N);

  mint ans = 0;
  rep(i, n) {
    ans += s.prod(0, a[i] + 1);
    s.apply(0, N, 2);
    s.set(a[i], s.get(a[i]) + 1);
  }
  wt(ans);
}
