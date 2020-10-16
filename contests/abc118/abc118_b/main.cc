#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector<int> food(m);
  rep(i, n) {
    ints(k);
    rep(j, k) {
      ints(a);
      food[a - 1]++;
    }
  }
  int ans = 0;
  rep(i, m) if (food[i] == n)++ ans;
  wt(ans);
}
