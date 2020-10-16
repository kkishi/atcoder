#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<bool> e(n, V<bool>(n));
  rep(m) {
    ints(a, b);
    --a, --b;
    e[a][b] = e[b][a] = true;
  }
  V<int> o(n);
  iota(all(o), 0);
  int ans = 0;
  do {
    bool ok = true;
    rep(i, n - 1) if (!e[o[i]][o[i + 1]]) ok = false;
    if (ok) ++ans;
  } while (next_permutation(o.begin() + 1, o.end()));
  wt(ans);
}
