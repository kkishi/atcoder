#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(c);
  map<char, int> mp;
  each(e, c)++ mp[e];
  int mi = big, ma = -big;
  rep(i, '1', '5') {
    chmin(mi, mp[i]);
    chmax(ma, mp[i]);
  }
  wt(ma, mi);
}
