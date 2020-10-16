#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  int l = 0;
  int x = 0;
  rep(r, n) {
    while (x & a[r]) {
      x ^= a[l];
      ++l;
    }
    x ^= a[r];
    ans += r - l + 1;
  }
  wt(ans);
}
