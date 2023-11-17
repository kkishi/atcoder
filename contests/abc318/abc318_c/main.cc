#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d, p);
  V<int> f(n);
  cin >> f;
  sort(f, greater{});
  int ans = 0;
  rep(i, div_ceil(n, d)) {
    int sum = 0;
    rep(j, d) if (i * d + j < n) sum += f[i * d + j];
    ans += min(p, sum);
  }
  wt(ans);
}
