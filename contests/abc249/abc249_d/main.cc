#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  map<int, int> mp;
  each(e, a)++ mp[e];
  each(k, v, mp) {
    for (int i = 1; i * i <= k; ++i) {
      if (k % i == 0) {
        int j = k / i;
        ans += v * mp[i] * mp[j] * (j == i ? 1 : 2);
      }
    }
  }
  wt(ans);
}
