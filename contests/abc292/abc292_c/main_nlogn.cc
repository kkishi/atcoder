#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> cnt(n);
  rep(a, 1, n) for (int b = 1; a * b < n; ++b)++ cnt[a * b];
  int ans = 0;
  rep(i, 1, n) ans += cnt[i] * cnt[n - i];
  wt(ans);
}
