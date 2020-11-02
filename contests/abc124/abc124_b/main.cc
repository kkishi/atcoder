#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> h(n);
  cin >> h;
  int maxi = 0;
  int ans = 0;
  rep(i, n) {
    if (h[i] >= maxi) ++ans;
    chmax(maxi, h[i]);
  }
  wt(ans);
}
