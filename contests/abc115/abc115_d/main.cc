#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  vector<int> p(n + 1);
  vector<int> b(n + 1);
  p[0] = 1;
  rep(i, n) {
    p[i + 1] = p[i] * 2 + 1;
    b[i + 1] = b[i] * 2 + 2;
  }
  wt(Fix([&p, &b](auto rec, int n, int x) -> int {
    if (n == 0) return 1LL;
    if (x <= 1) return 0LL;
    --x;
    int pb = p[n - 1] + b[n - 1];
    if (x <= pb) {
      return rec(n - 1, x);
    }
    x -= pb;
    int ps = p[n - 1];
    if (x <= 1) {
      return x + ps;
    }
    --x;
    ++ps;
    if (x <= pb) {
      return ps + rec(n - 1, x);
    }
    return ps + p[n - 1];
  })(n, x));
}
