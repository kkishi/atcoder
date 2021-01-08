#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, k);
  V<int> w(n), p(n);
  rep(i, n) cin >> w[i] >> p[i];
  wt(BinarySearch<double>(0, 100, [&](double x) {
    V<double> v;
    rep(i, n) v.pb(w[i] * (p[i] - x));
    sort(all(v), greater());
    return accumulate(v.begin(), v.begin() + k, double(0)) > 0;
  }));
}
