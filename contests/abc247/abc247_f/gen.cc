#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 5;
  wt(n);
  V<int> p(n), q(n);
  rep(i, n) {
    p[i] = i + 1;
    q[i] = i + 1;
  }
  Rand r;
  rep(i, n) swap(q[i], q[r.Int(i, n - 1)]);
  wt(p);
  wt(q);
}
