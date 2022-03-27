#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n + 1), c(n + m + 1);
  cin >> a >> c;
  V<int> b(m + 1);
  rep(i, m + 1) {
    int sum = 0;
    rep(j, i) {
      if (int x = n - i + j; x >= 0) {
        sum += a[x] * b[m - j];
      }
    }
    b[m - i] = (c[(m - i) + n] - sum) / a[n];
  }
  wt(b);
}
