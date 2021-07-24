#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<string> s(n);
  cin >> s;
  using B = uint64_t;
  set<B> seen;
  auto idx = [&n](int r, int c) { return r * n + c; };
  rep(i, n) rep(j, n) if (s[i][j] == '.') seen.insert(B(1) << idx(i, j));
  rep(k - 1) {
    set<B> nseen;
    each(mask, seen) rep(r, n) rep(c, n) if (hasbit(mask, idx(r, c))) {
      each(nr, nc, adjacent(r, c)) if (inside(nr, nc, n, n)) {
        if (s[nr][nc] == '#') continue;
        if (hasbit(mask, idx(nr, nc))) continue;
        nseen.insert(mask | (B(1) << idx(nr, nc)));
      }
    }
    swap(nseen, seen);
  }
  wt(sz(seen));
}
