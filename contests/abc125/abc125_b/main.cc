#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> v(n), c(n);
  cin >> v >> c;
  int ans = numeric_limits<int>::min();
  rep(s, 1 << n) {
    int x = 0, y = 0;
    rep(i, n) if (hasbit(s, i)) {
      x += v[i];
      y += c[i];
    }
    chmax(ans, x - y);
  }
  wt(ans);
}
