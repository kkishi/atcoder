#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  auto answer = [&](int l, int rv) {
    int r;
    rep(i, n) if (a[i] == rv) r = i;
    reverse(a.begin() + l, a.begin() + r + 1);
    wt(a);
    exit(0);
  };
  rep(i, n) {
    V<int> lo, hi;
    rep(j, i + 1, n)(a[j] < a[i] ? lo : hi).eb(a[j]);
    if (k <= sz(lo)) {
      sort(lo);
      answer(i, lo[k - 1]);
    }
    int offset = sz(lo) + (n - i) * (n - 1 - i) / 2 + (1 + i);
    if (offset < k) {
      sort(hi);
      answer(i, hi[k - 1 - offset]);
    }
    k -= sz(lo);
  }
  wt(a);
}
