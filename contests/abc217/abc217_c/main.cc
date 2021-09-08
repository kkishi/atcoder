#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  V<int> q(n);
  rep(i, n) q[p[i] - 1] = i + 1;
  wt(q);
}
