#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  int ta = big, ao = big;
  rep(mask, 1 << n) {
    int AO = popcount(mask);
    if (AO > k) continue;
    V<int> v(n);
    rep(i, n) if (hasbit(mask, i)) v[i] = true;
    int TA = 0;
    while (true) {
      int h = -big;
      rep(i, n) if (!v[i]) chmax(h, a[i]);
      if (h == -big) break;
      rep(i, n) if (a[i] * 2 > h) v[i] = true;
      ++TA;
    }
    if (chmin(ta, TA)) {
      ao = AO;
    } else if (ta == TA) {
      chmin(ao, AO);
    }
  }
  wt(ta, ao);
}
