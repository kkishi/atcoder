#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(h, w, t);
  vector s(h, vector(w, int(0)));
  cin >> s;
  CumulativeSum2D cs(s);
  int ans = big;
  rep(r1, h) rep(r2, r1, h) rep(c1, w) rep(c2, c1, w) {
    int mins = cs.Get(r1, c1, r2, c2);
    vector memo(h, vector(h, vector(w, vector(w, vector(t + 1, big)))));
    vector seen(h, vector(h, vector(w, vector(w, vector(t + 1, int(0))))));
    int maxs = Fix([&](auto rec, int r1, int r2, int c1, int c2, int t) -> int {
      int& m = memo[r1][r2][c1][c2][t];
      int& s = seen[r1][r2][c1][c2][t];
      if (!s) {
        s = true;
        if (t == 0) {
          int s = cs.Get(r1, c1, r2, c2);
          chmin(m, s >= mins ? s : big);
        } else {
          rep(nt, t) {
            rep(nr, r1, r2) chmin(m, max(rec(r1, nr, c1, c2, nt),
                                         rec(nr + 1, r2, c1, c2, t - 1 - nt)));
            rep(nc, c1, c2) chmin(m, max(rec(r1, r2, c1, nc, nt),
                                         rec(r1, r2, nc + 1, c2, t - 1 - nt)));
          }
        }
      }
      return m;
    })(0, h - 1, 0, w - 1, t);
    chmin(ans, maxs - mins);
  }
  wt(ans);
}
