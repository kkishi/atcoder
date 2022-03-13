#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> a(n + 1), b(n);
  cin >> a >> b;
  int sum = accumulate(b);
  rep(i, n) {
    int s = min(a[i], b[i]);
    b[i] -= s;
    a[i] -= s;
    s = min(a[i + 1], b[i]);
    b[i] -= s;
    a[i + 1] -= s;
  }
  wt(sum - accumulate(b));
}
