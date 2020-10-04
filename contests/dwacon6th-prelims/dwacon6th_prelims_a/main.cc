#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<string, int>> v(n);
  cin >> v;
  strings(x);
  rep(i, n) if (v[i].first == x) {
    int ans = 0;
    rep(j, i + 1, n) ans += v[j].second;
    wt(ans);
  }
}
