#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int s = accumulate(all(a), int());
  if (s % 10) return false;
  s /= 10;
  rep(i, n) a.pb(a[i]);
  int N = sz(a);
  V<int> b(N + 1);
  rep(i, N) b[i + 1] = b[i] + a[i];
  rep(i, n) if (*lower_bound(all(b), b[i] + s) == b[i] + s) return true;
  return false;
}

void Main() { wt(Solve()); }
