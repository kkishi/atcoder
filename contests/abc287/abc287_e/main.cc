#include <bits/stdc++.h>

#include "atcoder.h"
#include "rolling_hash.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  map<pair<int, uint64_t>, int> mp;
  each(e, s) {
    RollingHash h;
    rep(i, sz(e)) {
      h.PushBack(e[i]);
      mp[{i, h.hash()}]++;
    }
  }
  each(e, s) {
    RollingHash h;
    int ans = 0;
    rep(i, sz(e)) {
      h.PushBack(e[i]);
      if (mp[{i, h.hash()}] > 1) ans = i + 1;
    }
    wt(ans);
  }
}
