#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  sort(a);
  int ans = a[0];
  rep(i, n - 1) ans = gcd(ans, a[i + 1]);
  wt(ans);
}
