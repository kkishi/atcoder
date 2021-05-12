#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k, n, m);
  V<int> a(k);
  cin >> a;
  V<int> ans;
  VV<int> bs;
  rep(r, 2) {
    V<int> b(k);
    rep(i, k) b[i] = (a[i] * m + n * r) / n;
    dbg(r, b);
    int sb = accumulate(all(b), int(0));
    dbg(r, sb);
    V<pair<int, int>> d;
    rep(i, k) d.eb(b[i] * n - a[i] * m, i);
    sort(all(d));
    dbg(d);
    if (sb < m) {
      int D = (m - sb) / k;
      int R = (m - sb) % k;
      rep(i, k) b[i] += D;
      rep(i, R)++ b[d[i].second];
    } else {
      int D = (sb - m) / k;
      int R = (sb - m) % k;
      rep(i, k) b[i] -= D;
      rep(i, R)-- b[d[k - 1 - i].second];
    }
    assert(accumulate(all(b), int(0)) == m);
    int maxi = -big;
    rep(i, k) chmax(maxi, abs(b[i] * n - a[i] * m));
    ans.pb(maxi);
    bs.pb(b);
  }
  dbg(ans);
  if (ans[0] >= ans[1]) {
    wt(bs[0]);
  } else {
    wt(bs[1]);
  }
}
