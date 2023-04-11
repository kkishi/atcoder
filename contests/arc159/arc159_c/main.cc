#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  VV<int> ans;
  if (accumulate(a) % n) {
    // Try again after increasing the sum by n*(n+1)/2. For example, this is
    // necessary for the following input:
    // 2
    // 1 2
    V<int> p;
    rep(i, n) p.eb(i + 1);
    ans.eb(p);
    rep(i, n) a[i] += p[i];
    if (accumulate(a) % n) {
      wt(false);
      return;
    }
  }
  wt(true);

  // --a[i], ++a[j]
  auto move = [&](int i, int j) {
    V<int> p1;
    rep(k, n) p1.eb(k + 1);
    V<int> p2 = p1;
    reverse(p2);

    swap(p2[0], p2[1]);  // --a[0], ++a[1]

    swap(p1[0], p1[i]);  // Move 0 to i.
    swap(p2[0], p2[i]);

    int k = 1;  // Move 1 to j. Edge case: if i was 1, it's moved to 0.
    if (i == 1) k = 0;
    swap(p1[k], p1[j]);
    swap(p2[k], p2[j]);

    ans.eb(p1);
    ans.eb(p2);
  };
  while (true) {
    int ma = -big, mai;
    int mi = big, mii;
    rep(i, n) {
      if (chmax(ma, a[i])) mai = i;
      if (chmin(mi, a[i])) mii = i;
    }
    if (ma == mi) break;
    move(mai, mii);
    --a[mai], ++a[mii];
  }
  wt(sz(ans));
  each(e, ans) wt(e);
}
