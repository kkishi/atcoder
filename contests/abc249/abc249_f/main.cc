#include <bits/stdc++.h>
#include <pbds.h>

#include "add_segment_tree.h"
#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> t(n), y(n);
  rep(i, n) cin >> t[i] >> y[i];
  V<int> ct(n + 1);
  rrep(i, n) ct[i] = ct[i + 1] + (t[i] == 1);
  V<pair<int, int>> ys;
  rep(i, n) if (t[i] == 2) ys.eb(y[i], i);
  sort(ys);
  int N = sz(ys);
  V<int> idx(n);
  rep(i, N) idx[ys[i].second] = i;
  int sum = 0;
  Set<pair<int, int>> st;
  AddSegmentTree<int> tr(N);

  int ans = 0;
  rep(i, n) {
    if (t[i] == 1) {
      ans = y[i];
    } else {
      ans += y[i];
    }
  }
  auto f = [&](int rem, int x0) {
    if (rem < 0) return;
    int r = 0;
    if (rem > 0 && !st.empty()) {
      int pos = min(rem, sz(st)) - 1;
      auto it = st.find_by_order(pos);
      r = it->second + 1;
    }
    chmax(ans, x0 + sum - min(0, tr.Aggregate(0, r)));
  };
  rrep(i, n) {
    if (t[i] == 1) {
      f(k - ct[i + 1], y[i]);
    } else {
      sum += y[i];
      if (y[i] < 0) {
        st.insert({y[i], idx[i]});
        tr.Set(idx[i], y[i]);
      }
    }
  }
  f(k - ct[0], 0);
  wt(ans);
}
