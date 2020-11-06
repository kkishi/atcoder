#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  V<int> sp(n + 1);
  rep(i, n) sp[i + 1] = sp[i] + max(a[i], 0);
  V<int> sa(n + 1);
  rep(i, n) sa[i + 1] = sa[i] + a[i];
  int ans = 0;
  rep(i, n - k + 1) {
    // sum positive [~, i)
    // sum all [i, i+k)
    // sum positive [i+k, ~)
    chmax(ans, sp[i] + max(0, sa[i + k] - sa[i]) + sp[n] - sp[i + k]);
  }
  wt(ans);
}
