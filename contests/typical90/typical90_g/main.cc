#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  ints(q);
  rep(q) {
    ints(b);
    auto it = lower_bound(all(a), b);
    int ans = big;
    if (it != a.end()) chmin(ans, *it - b);
    if (it != a.begin()) chmin(ans, b - *prev(it));
    wt(ans);
  }
}
