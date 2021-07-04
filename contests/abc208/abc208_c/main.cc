#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<pair<int, int>> a(n);
  rep(i, n) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(all(a));
  V<int> ans(n, k / n);
  k %= n;
  rep(i, k) ans[a[i].second]++;
  each(e, ans) wt(e);
}
