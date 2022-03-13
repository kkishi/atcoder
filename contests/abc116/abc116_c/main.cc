#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> h(n);
  cin >> h;
  int ans = 0;
  while (true) {
    int maxi = max(h);
    if (maxi == 0) break;
    rep(i, n) if (h[i] == maxi) {
      for (int j = i; j < n && h[j] == maxi; ++j) {
        h[j]--;
      }
      break;
    }
    ++ans;
  }
  wt(ans);
}
