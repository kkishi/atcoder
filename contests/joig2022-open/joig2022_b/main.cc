#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n) rep(j, i + 1, n) rep(k, j + 1, n) if (a[i] * a[j] == a[k])++ ans;
  wt(ans);
}
