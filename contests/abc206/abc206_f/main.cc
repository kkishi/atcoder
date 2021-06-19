// This solution is no correct.
#include <bits/stdc++.h>

#include "atcoder.h"

using P = pair<int, int>;

void Solve() {
  ints(n);
  V<int> l(n), r(n);
  rep(i, n) cin >> l[i] >> r[i];
  V<P> seg;
  rep(i, n) seg.eb(l[i], r[i]);
  dbg(seg);
#define canw(x) hasbit(x, 0)
#define canl(x) hasbit(x, 1)
  vector dp(200, vector(200, int(-1)));
  auto rec = Fix([&](auto rec, int l, int r, const V<P>& seg) {
    int& d = dp[l][r];
    if (d != -1) return d;
    if (seg.empty()) {
      d = 2;  // Lose
    } else if (sz(seg) == 1) {
      d = 1;  // Win
    } else {
      d = 0;
      rep(i, sz(seg)) {
        V<P> L, R;
        rep(j, sz(seg)) {
          if (seg[j].second <= seg[i].first) L.eb(seg[j]);
          if (seg[j].first >= seg[i].second) R.eb(seg[j]);
        }
        int ld = rec(l, seg[i].first, L);
        int rd = rec(seg[i].second, r, R);
        if (!canw(ld) && !canw(rd)) {
          d |= 1;
        }
        if (!canl(ld) && !canl(rd)) {
          d |= 1;
        }
        if (!canl(ld) && !canw(rd)) {
          d |= 2;
        }
        if (!canw(ld) && !canl(rd)) {
          d |= 2;
        }
        if (ld == 3 && rd == 3) {
          d |= 1;
        } else if (ld == 3 || rd == 3) {
          d |= 2;
        }
      }
    }
    return d;
  });
  wt(canw(rec(0, 101, seg)) ? "Alice" : "Bob");
}

void Main() {
  ints(t);
  rep(t) Solve();
}
