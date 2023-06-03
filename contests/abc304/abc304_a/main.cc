#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<string, int>> v(n);
  cin >> v;
  int mi = big, mii;
  rep(i, n) if (chmin(mi, v[i].second)) mii = i;
  rep(i, n) wt(v[(mii + i) % n].first);
}
