#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d);
  V<int> r(n);
  cin >> r;
  sort(r);
  int ans = 0;
  rep(i, n) {
    auto it = prev(lower_bound(all(r), r[i] + d + 1));
    if (int x = it - (r.begin() + i) + 1; x >= 3) {
      ans += (x - 1) * (x - 2) / 2;
    }
  }
  wt(ans);
}
