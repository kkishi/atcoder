#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  V<pair<int, int>> c;
  rep(i, n) c.emplace_back(a[i] + b[i], i);
  sort(all(c), greater());
  int T = 0, A = 0;
  rep(i, n) {
    if (i % 2 == 0) {
      T += a[c[i].second];
    } else {
      A += b[c[i].second];
    }
  }
  wt(T - A);
}
