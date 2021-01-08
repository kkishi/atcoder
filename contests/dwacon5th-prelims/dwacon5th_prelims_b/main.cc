#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  V<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  V<int> b;
  rep(i, n) rep(j, i, n) b.pb(s[j + 1] - s[i]);
  int ans = 0;
  for (int i = 50; i >= 0; --i) {
    int bit = 1LL << i;
    int cnt = 0;
    for (int bi : b)
      if (((ans | bit) & bi) == (ans | bit)) ++cnt;
    if (cnt >= k) ans |= bit;
  }
  wt(ans);
}
