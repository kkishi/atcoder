#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, M, Q);
  V<int> p(M);
  VV<int> s(N);
  rep(Q) {
    ints(k);
    if (k == 1) {
      ints(n);
      int ans = 0;
      each(x, s[n - 1]) ans += N - p[x];
      wt(ans);
    } else {
      ints(n, m);
      ++p[m - 1];
      s[n - 1].pb(m - 1);
    }
  }
}
