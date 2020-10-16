#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> t(n), v(n);
  cin >> t >> v;

  rep(i, n) {
    t[i] *= 2;
    v[i] *= 2;
  }

  t.push_back(0);
  v.push_back(0);
  ++n;

  V<int> st(n + 1);
  rep(i, n) st[i + 1] = st[i] + t[i];

  int T = st[n];
  V<int> maxi(T + 1, numeric_limits<int>::max());
  rep(i, n) {
    rep(j, st[i], st[i + 1] + 1) chmin(maxi[j], v[i]);
    for (int t = st[i]; t >= 0; --t) {
      chmin(maxi[t], v[i] + (st[i] - t));
    }
  }
  rep(i, T + 1) { dbg(i * 0.5, maxi[i] * 0.5); }
  double ans = 0;
  {
    int v = 0;
    rep(i, T + 1) {
      assert(v <= maxi[i]);
      int nv = min(v + 1, maxi[i + 1]);
      ans += (nv + v) / 2.0;
      v = nv;
      dbg(i / 2.0, v / 2.0, ans / 4.0);
    }
  }
  cout << fixed << setprecision(15);
  wt(ans / 4);
}
