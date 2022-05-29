#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, w);
  V<int> a(n);
  cin >> a;
  V<int> good(w + 1);
  auto f = [&](int s) {
    if (s <= w) good[s] = 1;
  };
  rep(i, n) {
    f(a[i]);
    rep(j, i) {
      f(a[i] + a[j]);
      rep(k, j) f(a[i] + a[j] + a[k]);
    }
  }
  wt(accumulate(good));
}
