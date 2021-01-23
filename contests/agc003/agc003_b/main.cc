#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  int carry = 0;
  rep(i, n) {
    int p = min(carry, a[i]);
    carry -= p;
    a[i] -= p;
    ans += p;
    ans += a[i] / 2;
    carry = a[i] % 2;
  }
  wt(ans);
}
