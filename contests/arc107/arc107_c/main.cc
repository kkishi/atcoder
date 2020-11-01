#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  VV<int> a(n, V<int>(n));
  cin >> a;
  DisjointSet rs(n), cs(n);
  rep(i, n - 1) rep(j, i + 1, n) {
    {
      bool ok = true;
      rep(c, n) if (a[i][c] + a[j][c] > k) ok = false;
      if (ok) rs.Union(i, j);
    }
    {
      bool ok = true;
      rep(r, n) if (a[r][i] + a[r][j] > k) ok = false;
      if (ok) cs.Union(i, j);
    }
  }
  auto f = [&](DisjointSet& ds) {
    set<int> g;
    mint ret = 1;
    rep(i, n) if (g.insert(ds.Find(i)).second) ret *= mint::Fact(ds.Size(i));
    return ret;
  };
  wt(f(rs) * f(cs));
}
