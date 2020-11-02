#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  map<int, int> as;
  rep(i, n) {
    ints(a);
    ++as[a];
  }
  rep(i, m) {
    ints(b, c);
    int changed = 0;
    while (changed < n && b > 0) {
      auto [k, v] = *as.begin();
      if (k >= c) {
        break;
      }
      int change = min(b, v);
      if (change == v) {
        as.erase(as.begin());
      } else {
        as[k] -= change;
      }
      changed += change;
      b -= change;
    }
    as[c] += changed;
  }
  int ans = 0;
  for (auto [k, v] : as) ans += k * v;
  wt(ans);
}
