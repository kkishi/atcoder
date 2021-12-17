#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  map<int, int> mp;
  rep(n) {
    ints(a);
    ++mp[a];
  }
  int ans = 0;
  rep(m) {
    ints(b);
    ans += mp[b];
    mp[b] = 0;
  }
  wt(ans);
}
