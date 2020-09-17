#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n + 1);
  rep(i, n) cin >> a[i + 1];
  int sum = 0;
  rep(i, k - 1) sum += a[i + 1];
  int ans = 0;
  rep(i, k - 1, n) {
    (sum += a[i + 1]) -= a[i - (k - 1)];
    ans += sum;
  }
  wt(ans);
}
