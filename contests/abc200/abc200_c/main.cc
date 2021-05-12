#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> cnt(200);
  int ans = 0;
  rep(i, n) {
    int m = a[i] % 200;
    ans += cnt[m];
    ++cnt[m];
  }
  wt(ans);
}
