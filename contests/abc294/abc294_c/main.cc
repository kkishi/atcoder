#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  V<int> c;
  each(e, a) c.eb(e);
  each(e, b) c.eb(e);
  sort(c);
  map<int, int> mp;
  rep(i, sz(c)) mp[c[i]] = i + 1;
  {
    V<int> ans;
    each(e, a) ans.eb(mp[e]);
    wt(ans);
  }
  {
    V<int> ans;
    each(e, b) ans.eb(mp[e]);
    wt(ans);
  }
}
