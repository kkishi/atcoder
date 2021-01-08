#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector connected(m, V<bool>(n));
  rep(i, m) {
    ints(k);
    rep(k) {
      ints(s);
      connected[i][s - 1] = true;
    }
  }
  vector<int> p(m);
  cin >> p;
  int ans = 0;
  rep(s, 1 << n) {
    rep(i, m) {
      int cnt = 0;
      rep(j, n) {
        if (connected[i][j] && hasbit(s, j)) {
          ++cnt;
        }
      }
      if (cnt % 2 != p[i]) goto next;
    }
    ++ans;
  next:
    continue;
  }
  wt(ans);
}
