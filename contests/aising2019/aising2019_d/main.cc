#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);

  V<int> a(n);
  cin >> a;

  V<pair<int, int>> qs;
  rep(i, q) {
    ints(x);
    qs.pb({x, i});
  }
  sort(all(qs));
  reverse(all(qs));

  V<int> rsum(n + 1);
  rrep(i, n) rsum[i] = a[i] + rsum[i + 1];
  V<int> tsum(n + 1);
  rep(i, n) tsum[i + 1] = tsum[i] + (i % 2 != n % 2 ? a[i] : 0);
  int l = n - 3;
  int r = n - 2;
  V<int> ans(q);
  for (auto [x, i] : qs) {
    while (l >= 0 && abs(a[l] - x) <= abs(a[r] - x)) {
      l -= 2;
      r -= 1;
    }
    if (l < 0) {
      ans[i] = rsum[n / 2];
    } else {
      ans[i] = rsum[r + 1] + tsum[l + 1];
    }
  }
  rep(i, q) wt(ans[i]);
}
