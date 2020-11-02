#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  V<int> c(m), d(m);
  rep(i, m) cin >> c[i] >> d[i];
  cout << fixed << setprecision(20);
  wt(BinarySearch<double>(0, 1e20, [&](double x) {
    V<double> v;
    rep(i, n) v.push_back(b[i] - a[i] * x);
    double w = numeric_limits<double>::lowest();
    rep(i, m) chmax(w, d[i] - c[i] * x);
    v.push_back(w);
    sort(all(v), greater());
    return accumulate(v.begin(), v.begin() + 5, double(0)) > 0;
  }));
}
