#include <bits/stdc++.h>

#include "atcoder.h"

using P = pair<int, int>;

void Solve() {
  ints(n);
  V<int> l(n), r(n);
  rep(i, n) cin >> l[i] >> r[i];
  V<P> seg;
  rep(i, n) seg.eb(l[i], r[i]);
  vector dp(200, vector(200, int(-1)));
  auto rec = Fix([&](auto rec, int l, int r, const V<P>& seg) {
    int& d = dp[l][r];
    if (d != -1) return d;
    if (seg.empty()) {
      d = 0;
    } else {
      set<int> st;
      rep(i, sz(seg)) {
        V<P> L, R;
        rep(j, sz(seg)) {
          if (seg[j].second <= seg[i].first) L.eb(seg[j]);
          if (seg[j].first >= seg[i].second) R.eb(seg[j]);
        }
        int ld = rec(l, seg[i].first, L);
        int rd = rec(seg[i].second, r, R);
        st.insert(ld ^ rd);
      }
      for (int i = 0;; ++i) {
        if (st.count(i) == 0) {
          d = i;
          break;
        }
      }
    }
    return d;
  });
  wt(rec(0, 101, seg) ? "Alice" : "Bob");
}

void Main() {
  ints(t);
  rep(t) Solve();
}
