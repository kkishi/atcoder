#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(h, w);
  auto idx = [&](int i, int j) { return i * w + j; };
  DisjointSet ds(h * w);
  vector g(h, vector(w, false));
  ints(q);
  rep(q) {
    ints(t);
    if (t == 1) {
      ints(r, c);
      --r, --c;
      g[r][c] = true;
      each(nr, nc, adjacent(r, c)) {
        if (inside(nr, nc, h, w)) {
          if (g[nr][nc]) {
            ds.Union(idx(r, c), idx(nr, nc));
          }
        }
      }
    } else {
      ints(ra, ca, rb, cb);
      --ra, --ca, --rb, --cb;
      wt(g[ra][ca] && g[rb][cb] && ds.Same(idx(ra, ca), idx(rb, cb)));
    }
  }
}
