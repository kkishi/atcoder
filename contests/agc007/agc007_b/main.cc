#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n);
  rep(i, n) {
    ints(pi);
    p[pi - 1] = i + 1;
  }

  V<int> a(n);
  a[0] = 1;
  rep(i, n - 1) a[i + 1] = a[i] + 1 + max(0, p[i + 1] - p[i]);
  V<int> b(n);
  b[n - 1] = 1;
  rrep(i, n - 1) b[i] = b[i + 1] + 1 + max(0, p[i] - p[i + 1]);

  wt(a);
  wt(b);
}
