#include <bits/stdc++.h>

#include "atcoder.h"

struct S {
  int a, b;
};

void Main() {
  ints(n, h);
  V<S> v;
  rep(n) {
    ints(a, b);
    v.pb({a, b});
  }
  sort(v, [](auto& x, auto& y) { return x.b * y.a < y.b * x.a; });
  V<int> dp(h + 1, int(-1));
  dp[h] = 0;
  each(e, v) rep(j, h + 1) if (dp[j] != -1) {
    chmax(dp[max(0, j - e.b)], dp[j] + j * e.a);
  }
  wt(max(dp));
}
