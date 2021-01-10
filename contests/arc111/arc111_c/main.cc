#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n), p(n);
  cin >> a >> b >> p;
  each(pi, p)-- pi;

  V<int> idx(n);
  iota(all(idx), 0);
  sort(all(idx), [&](int i, int j) { return a[i] < a[j]; });

  map<int, int> m;
  rep(i, n) m[p[i]] = i;

  V<pair<int, int>> ans;
  each(I, idx) {
    // a[I] has b[P[I]]
    if (p[I] != I) {
      int J = m[I];
      // a[J] has b[I]  (p[J] = I)
      if (a[I] <= b[p[I]] || a[J] <= b[p[J]]) {
        wt(-1);
        return;
      }
      m[p[J]] = I;
      m[p[I]] = J;
      swap(p[I], p[J]);
      ans.eb(I, J);
    }
  }
  wt(sz(ans));
  each(i, j, ans) wt(i + 1, j + 1);
}
