#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = numeric_limits<int>::max();
  for (int i = 1; i * i <= n; ++i) {
    int j = n / i;
    chmin(ans, abs(i - j) + n - (i * j));
  }
  wt(ans);
}
