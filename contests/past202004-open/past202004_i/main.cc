#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> a(1 << n);
  rep(i, 1 << n) {
    a[i].first = i;
    cin >> a[i].second;
  }
  V<int> ans(1 << n);
  Fix([&](auto rec, int begin, int end, int x) -> pair<int, int> {
    if (end - begin == 1) return a[begin];
    int mid = (begin + end) / 2;
    auto [li, lv] = rec(begin, mid, x - 1);
    auto [ri, rv] = rec(mid, end, x - 1);
    ans[li] = ans[ri] = x;
    if (lv < rv) {
      return {ri, rv};
    } else {
      return {li, lv};
    }
  })(0, 1 << n, n);
  each(e, ans) wt(e);
}
