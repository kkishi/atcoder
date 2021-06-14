#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> l(n);
  {
    V<int> v;
    rep(i, n) {
      auto it = lower_bound(all(v), a[i]);
      if (it == v.end()) {
        v.pb(a[i]);
      } else {
        *it = a[i];
      }
      l[i] = sz(v);
    }
  }
  V<int> r(n);
  {
    V<int> v;
    rrep(i, n) {
      auto it = lower_bound(all(v), a[i]);
      if (it == v.end()) {
        v.pb(a[i]);
      } else {
        *it = a[i];
      }
      r[i] = sz(v);
    }
  }
  int ans = -big;
  rep(i, n) chmax(ans, l[i] + r[i] - 1);
  wt(ans);
}
