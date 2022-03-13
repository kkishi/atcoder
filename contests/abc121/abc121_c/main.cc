#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector<pair<int, int>> ab(n);
  rep(i, n) cin >> ab[i].first >> ab[i].second;
  sort(ab);
  int ans = 0;
  for (int i = 0; m > 0; ++i) {
    int dm = min(m, ab[i].second);
    ans += ab[i].first * dm;
    m -= dm;
  }
  wt(ans);
}
