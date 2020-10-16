#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 1LL << 60;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      chmin(ans, (i - 1) + (n / i - 1));
    }
  }
  wt(ans);
}
