#include <bits/stdc++.h>

#include "atcoder.h"

bool check(int s, const VV<pair<int, int>>& v) {
  rep(i, v.size()) {
    if (!hasbit(s, i)) continue;
    each(p, v[i]) {
      int j = p.first;
      bool honest = hasbit(s, j);
      if (p.second == 1 != honest) {
        return false;
      }
    }
  }
  return true;
}

void Main() {
  ints(n);
  VV<pair<int, int>> v(n);
  rep(i, n) {
    ints(a);
    rep(j, a) {
      ints(x, y);
      v[i].push_back({x - 1, y});
    }
  }
  int ans = 0;
  rep(s, 1 << n) {
    if (check(s, v)) {
      chmax(ans, popcount(s));
    }
  }
  wt(ans);
}
