#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(n, q);
  V<string> p(n);
  cin >> p;

  vector g(n, vector(n, int(0)));
  rep(i, n) rep(j, n) g[i][j] = p[i][j] == 'B';
  CumulativeSum2D cs(g);
  auto f = [&](int r, int c) {
    ++r, ++c;
    int R = r / n;
    int C = c / n;
    r %= n;
    c %= n;
    int ret = R * C * cs.Get(n - 1, n - 1);
    if (r > 0) ret += C * cs.Get(r - 1, n - 1);
    if (c > 0) ret += R * cs.Get(n - 1, c - 1);
    if (r > 0 && c > 0) ret += cs.Get(r - 1, c - 1);
    return ret;
  };
  rep(q) {
    ints(a, b, c, d);
    wt(f(c, d) - f(a - 1, d) - f(c, b - 1) + f(a - 1, b - 1));
  }
}
