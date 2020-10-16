#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  int ans = 0;
  for (int b = k + 1; b <= n; ++b)
    for (int a = k; a <= n; a += b)
      ans += max(0, min(b - k, n - a + 1) - (a == 0 ? 1 : 0));
  wt(ans);
}
