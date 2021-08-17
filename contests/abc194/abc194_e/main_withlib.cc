#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;

  Intervals is;
  int ans = big;
  V<int> cnt(2000000);
  rep(i, n) {
    if (cnt[a[i]]++ == 0) is.Insert(a[i], a[i] + 1);
    int j = i - m;
    if (j >= 0 && --cnt[a[j]] == 0) is.Erase(a[j], a[j] + 1);
    if (i >= m - 1) chmin(ans, is.Mex(0));
  }
  wt(ans);
}
