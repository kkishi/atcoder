#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"
#include "modint.h"

using mint = ModInt<998244353>;

struct F {
  mint a, b;
};

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  DualSegmentTree<F> t(
      n,
      [](F f, F g) -> F {
        return F{f.a * g.a, f.a * g.b + f.b};
      },
      F{1, 0});
  rep(i, n) t.Update(i, i + 1, F{0, a[i]});
  rep(m) {
    ints(l, r, x);
    --l;
    mint w = r - l;
    t.Update(l, r, F{(w - 1) / w, x / w});
  }
  V<mint> ans;
  rep(i, n) ans.eb(t.Get(i).b);
  wt(ans);
}
