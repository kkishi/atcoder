#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  vector a(4, vector(4, int(0)));
  cin >> a;
  int ans = 0;
  rep(mask, 1 << 16) {
    auto idx = [](int i, int j) { return 4 * i + j; };
    auto has = [&](int i, int j) { return hasbit(mask, idx(i, j)); };
    auto check = [&] {
      rep(i, 4) rep(j, 4) if (a[i][j] && !has(i, j)) return false;
      int li, lj;
      DisjointSet ds(4 * 4);
      rep(i, 4) rep(j, 4) if (has(i, j)) {
        li = i, lj = j;
        each(ni, nj, adjacent(i, j)) if (inside(ni, nj, 4, 4) && has(ni, nj)) {
          ds.Union(idx(i, j), idx(ni, nj));
        }
      }
      rep(i, 4) rep(j, 4) if (has(i, j)) {
        if (!ds.Same(idx(i, j), idx(li, lj))) return false;
      }
      ds = DisjointSet(4 * 4 + 1);
      int S = 16;
      rep(i, 4) rep(j, 4) {
        if (i == 0 || i == 3 || j == 0 || j == 3) {
          ds.Union(idx(i, j), S);
        }
      }
      rep(i, 4) rep(j, 4) if (!has(i, j)) {
        each(ni, nj, adjacent(i, j)) if (inside(ni, nj, 4, 4) && !has(ni, nj)) {
          ds.Union(idx(i, j), idx(ni, nj));
        }
      }
      rep(i, 4) rep(j, 4) if (!has(i, j)) {
        if (!ds.Same(idx(i, j), S)) return false;
      }
      return true;
    };
    if (check()) {
      ++ans;
    }
  }
  wt(ans);
}
