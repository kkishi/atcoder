#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n);
  map<int, int> m;
  rep(n) {
    ints(a);
    ++m[a];
  }
  if (sz(m) > 2) return false;
  if (sz(m) == 1) {
    auto [k, _] = *m.begin();
    if (n >= k * 2) return true;
    return k == n - 1;
  }
  auto [xk, xv] = *m.begin();
  auto [yk, yv] = *next(m.begin());
  if (yk != xk + 1) return false;
  if (xv > xk) return false;
  return (n - xv) >= (xk - xv + 1) * 2;
}

void Main() { wt(Solve()); }
