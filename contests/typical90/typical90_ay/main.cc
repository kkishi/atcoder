#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k, p);
  V<int> a(n);
  cin >> a;
  int l = n / 2;
  int r = n - l;
  VV<int> L(l + 1), R(r + 1);
  rep(mask, 1 << l) {
    int sum = 0;
    rep(i, l) if (hasbit(mask, i)) sum += a[i];
    L[popcount(mask)].pb(sum);
  }
  rep(i, l + 1) sort(L[i]);
  rep(mask, 1 << r) {
    int sum = 0;
    rep(i, r) if (hasbit(mask, i)) sum += a[l + i];
    R[popcount(mask)].pb(sum);
  }
  rep(i, r + 1) sort(R[i]);
  int ans = 0;
  rep(i, k + 1) {
    int j = k - i;
    if (i > l || j > r) continue;
    each(e, L[i]) {
      // e + f <= p
      // f <= p - e + 1
      auto it = lower_bound(all(R[j]), p - e + 1);
      ans += it - R[j].begin();
      /*
      each(f, R[j]) {
        if (e + f <= p) ++ans;
      }
      */
    }
  }
  wt(ans);
}
