#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, c);
  V<pair<int, int>> v;
  rep(n) {
    ints(a, b, c);
    v.eb(a, c);
    v.eb(b + 1, -c);
  }
  v.eb(0, 0);
  sort(all(v));
  int ans = 0;
  int curr = 0;
  rep(i, sz(v)) {
    curr += v[i].second;
    ans += (v[i + 1].first - v[i].first) * min(c, curr);
  }
  wt(ans);
}
