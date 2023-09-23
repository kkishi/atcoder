#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, p);
  V<int> a(n), b(m);
  cin >> a >> b;
  sort(b);
  V<int> sb(m + 1);
  rep(i, m) sb[i + 1] = sb[i] + b[i];
  int ans = 0;
  each(e, a) {
    if (e >= p) {
      ans += m * p;
    } else {
      auto it = lower_bound(all(b), p - e);
      int lo = it - b.begin();
      int hi = b.end() - it;
      ans += lo * e + sb[lo];
      ans += hi * p;
    }
  }
  wt(ans);
}
