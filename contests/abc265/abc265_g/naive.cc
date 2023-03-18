#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  rep(q) {
    ints(t, l, r);
    --l;
    if (t == 1) {
      int ans = 0;
      rep(i, l, r) rep(j, i + 1, r) if (a[i] > a[j])++ ans;
      wt(ans);
    } else {
      ints(s, t, u);
      array<int, 3> f = {s, t, u};
      rep(i, l, r) a[i] = f[a[i]];
    }
  }
}
