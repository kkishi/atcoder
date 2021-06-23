#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  V<int> b(n - 1);
  rep(i, n - 1) b[i] = a[i + 1] - a[i];
  int sum = 0;
  rep(i, n - 1) sum += abs(b[i]);
  rep(q) {
    ints(l, r, v);
    l -= 2;
    if (l >= 0) {
      sum -= abs(b[l]);
      b[l] += v;
      sum += abs(b[l]);
    }
    r -= 1;
    if (r < n - 1) {
      sum -= abs(b[r]);
      b[r] -= v;
      sum += abs(b[r]);
    }
    wt(sum);
  }
}
