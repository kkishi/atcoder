#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  map<int, int> m;
  rep(n) {
    ints(a);
    ++m[a];
  }
  int ans = 0;
  while (k && !m.empty()) {
    auto maxi = prev(m.end());
    auto [x, y] = *maxi;
    int nx = 0;
    auto nmaxi = m.end();
    if (maxi != m.begin()) {
      nmaxi = prev(maxi);
      nx = nmaxi->first;
    }
    int K = (x - nx) * y;
    auto f = [](int x) { return x * (x + 1) / 2; };
    if (K <= k) {
      int z = (f(x) - f(nx)) * y;
      ans += z;
      m.erase(maxi);
      nmaxi->second += y;
      k -= K;
    } else {
      int dx = k / y;
      int z = (f(x) - f(x - dx)) * y;
      z += (k % y) * (x - dx);
      ans += z;
      k = 0;
    }
  }
  wt(ans);
}
