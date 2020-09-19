#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(a, 1, n + 1) {
    int mini = 1;
    int maxi = (n - 1) / a;
    ans += maxi - mini + 1;
  }
  wt(ans);
}
