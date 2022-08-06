#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(n, l, r);
  V<int> a(n);
  cin >> a;
  int s = accumulate(a);
  CumulativeSum1D c(a);
  multiset<int> mp;
  mp.insert(0);
  rep(i, n) mp.insert(r * (n - i) - c.Get(i, n - 1));
  int ans = s + *mp.begin();
  rep(i, n) {
    s -= a[i];
    s += l;
    mp.erase(mp.find(r * (n - i) - c.Get(i, n - 1)));
    chmin(ans, s + *mp.begin());
  }
  wt(ans);
}
