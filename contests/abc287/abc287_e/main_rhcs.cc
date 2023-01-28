#include <bits/stdc++.h>

#include "atcoder.h"
#include "rolling_hash_cumulative_sum.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  V<RollingHashCumulativeSum> v;
  each(e, s) v.eb(RollingHashCumulativeSum(e));
  map<pair<int, uint64_t>, int> mp;
  rep(i, n) rep(j, sz(s[i])) mp[{j, v[i].Hash(j + 1)}]++;
  rep(i, n) {
    int ans = 0;
    rep(j, sz(s[i])) if (mp[{j, v[i].Hash(j + 1)}] > 1) ans = j + 1;
    wt(ans);
  }
}
