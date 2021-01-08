#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  int plus = 0;
  int minus = 0;
  for (int ai : a) {
    if (ai > 0) ++plus;
    if (ai < 0) ++minus;
  }
  int sum = 0;
  V<pair<int, int>> ans;
  if (plus == 0) {
    sum = a.back();
    rep(i, n - 1) {
      ans.eb(sum, a[i]);
      sum -= a[i];
    }
  } else if (minus == 0) {
    sum = a[0];
    rep(i, 1, n - 1) {
      ans.eb(sum, a[i]);
      sum -= a[i];
    }
    ans.eb(a.back(), sum);
    sum = a.back() - sum;
  } else {
    sum = a[0];
    rep(i, 1, plus) {
      ans.eb(sum, a[n - 1 - i]);
      sum -= a[n - 1 - i];
    }
    ans.eb(a.back(), sum);
    sum = a.back() - sum;
    rep(i, 1, minus) {
      ans.eb(sum, a[i]);
      sum -= a[i];
    }
    rep(i, n - (plus + minus)) ans.eb(sum, 0);
  }
  wt(sum);
  for (auto [x, y] : ans) wt(x, y);
}
