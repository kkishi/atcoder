#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector<int> h(n);
  cin >> h;
  sort(h);
  int ans = h[n - 1] - h[0];
  rep(i, n) if (i + k - 1 < n) chmin(ans, h[i + k - 1] - h[i]);
  wt(ans);
}
