#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  map<pair<int, int>, int> dp;
  wt(Fix([&](auto rec, int depth, int val) {
    if (depth == n - 1) return val;
    auto [it, ok] = dp.insert({{depth, val}, 0});
    if (ok) {
      int p = a[depth + 1] / a[depth];
      int m = val % p;
      if (m == 0) {
        it->second = rec(depth + 1, val / p);
      } else {
        it->second = min(rec(depth + 1, (val - m) / p) + m,
                         rec(depth + 1, (val - m + p) / p) + p - m);
      }
    }
    return it->second;
  })(0, x));
}
