#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  double ans = 0;
  V<double> f(n + 1);
  rep(i, 2, n + 1) f[i] = f[i - 1] + log(i);
  rep(i, n) {
    int cnt = 0;
    rep(j, n) if (j != i && c[i] % c[j] == 0)++ cnt;
    for (int j = 0; j <= cnt; j += 2) {
      for (int k = 0; k <= n - 1 - cnt; ++k) {
        int l = j + k;
        int r = n - 1 - l;
        auto comb = [&](int n, int m) { return f[n] - f[m] - f[n - m]; };
        ans += exp(comb(cnt, j) + comb(n - 1 - cnt, k) + f[l] + f[r] - f[n]);
      }
    }
  }
  wt(ans);
}
