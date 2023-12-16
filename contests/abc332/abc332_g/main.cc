#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d);
  V<int> w(n);
  cin >> w;
  double avg = 0;
  each(e, w) avg += e;
  avg /= d;
  sort(w);
  dbg(avg, w);
  V<int> sum(d);
  rep(i, d) {
    sum[i] = w.back();
    w.pop_back();
  }
  int N = n - d;
  double ans = big;
  Fix([&](auto rec, int depth) {
    if (depth == N) {
      double x = 0;
      rep(i, d) x += (sum[i] - avg) * (sum[i] - avg);
      chmin(ans, d);
      return;
    }
    rep(i, d) {
      sum[i] += w[depth];
      rec(depth + 1);
      sum[i] -= w[depth];
    }
  })(0);
  wt(ans / (double)d);
}
