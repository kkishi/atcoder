#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, k);
  Graph g(n);
  g.Read(m);
  V<int> cnt(2);
  each(e, g)++ cnt[sz(e) % 2];
  mint ans = 0;
  for (int i = 0; i <= k; i += 2) {
    ans += mint::Comb(cnt[0], k - i) * mint::Comb(cnt[1], i);
  }
  wt(ans);
}
