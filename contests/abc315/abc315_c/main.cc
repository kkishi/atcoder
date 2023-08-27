#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> f(n), s(n);
  rep(i, n) cin >> f[i] >> s[i];
  int ans = -big;
  {
    map<int, int> mp;
    rep(i, n) chmax(mp[f[i]], s[i]);
    V<int> v;
    each(_, e, mp) v.eb(e);
    sort(v, greater{});
    if (sz(v) >= 2) chmax(ans, v[0] + v[1]);
  }
  {
    map<int, V<int>> mp;
    rep(i, n) mp[f[i]].eb(s[i]);
    each(_, e, mp) {
      sort(e, greater{});
      if (sz(e) >= 2) chmax(ans, e[0] + e[1] / 2);
    }
  }
  wt(ans);
}
