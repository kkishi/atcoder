#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N);
  V<string> s(N);
  cin >> s;

  // Log of factorial.
  V<double> f(N + 1);
  rep(i, N) f[i + 1] = f[i] + log(i + 1);

  double ans = 0;
  rep(i, N) {
    V<bool> seen(N);
    // Number of (transitive) parent nodes.
    int p = Fix([&](auto rec, int n) {
              if (seen[n]) return int(0);
              seen[n] = true;
              int ret = 1;
              rep(i, N) if (s[i][n] == '1') ret += rec(i);
              return ret;
            })(i) -
            1;
    double x = f[p] - f[N];
    rep(i, N - p - 1) x += log(p + 2 + i);
    ans += exp(x);
  }
  wt(ans);
}
