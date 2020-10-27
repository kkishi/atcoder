#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  V<int> h(n), s(n);
  rep(i, n) cin >> h[i] >> s[i];
  wt(BinarySearch<int>(numeric_limits<int>::max(), 0, [&](int x) {
    V<int> v;
    rep(i, n) {
      if (h[i] > x) return false;
      int t = (x - h[i]) / s[i];
      v.push_back(t);
    }
    sort(all(v));
    rep(i, n) if (v[i] < i) return false;
    return true;
  }));
}
