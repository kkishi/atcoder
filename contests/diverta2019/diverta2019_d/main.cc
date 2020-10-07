#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      if (int x = (n / i) - 1; x > i) ans += x;
    }
  }
  wt(ans);
}
