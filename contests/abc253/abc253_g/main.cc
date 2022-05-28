#include <bits/stdc++.h>

#include "atcoder.h"

V<int> naive(int n, int l, int r) {
  --l, --r;
  V<pair<int, int>> v;
  rep(y, n) rep(x, y) v.eb(x, y);
  sort(v);
  V<int> a(n);
  iota(all(a), 1);
  rep(i, l, r + 1) {
    auto [x, y] = v[i];
    swap(a[x], a[y]);
  }
  return a;
}

V<int> solve(int n, int l, int r) {
  --l, --r;
  int xl, yl, xr, yr;
  {
    int sum = 0;
    rep(i, n - 1) {
      int nsum = sum + n - 1 - i;
      if (sum <= l && l < nsum) {
        xl = i;
        yl = l - sum + i + 1;
      }
      if (sum <= r && r < nsum) {
        xr = i;
        yr = r - sum + i + 1;
      }
      sum = nsum;
    }
  }
  V<int> a(n);
  iota(all(a), 1);
  if (xl < xr) {
    rep(i, yl, n) swap(a[xl], a[i]);
    ++xl;
    yl = xl + 1;
  }
  list<int> L(all(a));
  auto it = next(L.begin(), xl);
  rep(i, xl, xr) {
    int x = L.back();
    L.pop_back();
    L.insert(it, x);
    ++xl;
    yl = xl + 1;
  }
  a = V<int>(all(L));
  rep(i, yl, yr + 1) swap(a[xl], a[i]);
  return a;
}

void Main() {
  ints(n, l, r);
  wt(solve(n, l, r));
  /*
  rep(n, 1, 5) rep(r, 1, n * (n - 1) / 2 + 1) rep(l, 1, r) {
    V<int> N = naive(n, l, r);
    V<int> S = solve(n, l, r);
    assert(N == S);
  }
  */
}
