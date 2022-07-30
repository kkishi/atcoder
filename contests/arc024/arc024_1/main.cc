#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l, r);
  map<int, int> mp;
  rep(l) {
    ints(x);
    ++mp[x];
  }
  int ans = 0;
  rep(r) {
    ints(x);
    if (mp[x]-- > 0) ++ans;
  }
  wt(ans);
}
