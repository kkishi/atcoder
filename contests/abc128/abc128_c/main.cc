#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector<vector<bool>> connected(m, vector(n, false));
  rep(i, m) {
    ints(k);
    while (k--) {
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
