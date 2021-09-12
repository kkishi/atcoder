#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"

void Main() {
  ints(n, d, k);
  V<int> l(d), r(d);
  rep(i, d) cin >> l[i] >> r[i];
  V<int> s(k), t(k);
  rep(i, k) cin >> s[i] >> t[i];

  V<int> v;
  rep(i, d) {
    v.pb(l[i]);
    v.pb(r[i]);
  }
  rep(i, k) {
    v.pb(s[i]);
    v.pb(t[i]);
  }
  Compressor c(v);

  V<int> ans;
  rep(i, k) {
    int si = c(s[i]);
    int ti = c(t[i]);
    V<bool> v(sz(c.coord));
    v[si] = true;
    rep(i, d) {
      int li = c(l[i]);
      int ri = c(r[i]);
      bool found = false;
      for (int j = li; j <= ri; ++j) {
        if (v[j]) found = true;
      }
      if (found) {
        for (int j = li; j <= ri; ++j) {
          v[j] = true;
        }
      }
      if (v[ti]) {
        ans.pb(i + 1);
        break;
      }
    }
  }
  rep(i, k) wt(ans[i]);
}
