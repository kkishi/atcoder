#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  ints(a);
  int ans = a - 1;
  int maxi = 1;
  rep(n - 1) {
    ints(a);
    if (a <= maxi) continue;
    if (a == maxi + 1) {
      ++maxi;
      continue;
    }
    int x = a - maxi;
    int y = x / (maxi + 1);
    ans += y;
    int z = a - (maxi + 1) * y;
    if (z > maxi + 1) {
      ++ans;
    }
  }
  wt(ans);
}
