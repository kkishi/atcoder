#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  while (true) {
    int sum = 0;
    rep(i, n) {
      int d = a[i] / n;
      sum += d;
      a[i] -= d * n + d;
    }
    if (sum == 0) break;
    ans += sum;
    rep(i, n) a[i] += sum;
  }
  wt(ans);
}
