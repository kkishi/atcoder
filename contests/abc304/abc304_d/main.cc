#include <bits/stdc++.h>

#include "atcoder.h"
#include "count.h"

void Main() {
  ints(w, h, n);
  V<int> p(n), q(n);
  rep(i, n) cin >> p[i] >> q[i];
  ints(A);
  V<int> a(A);
  cin >> a;
  ints(B);
  V<int> b(B);
  cin >> b;
  map<pair<int, int>, int> mp;
  rep(i, n)++ mp[{CountLE(a, p[i]), CountLE(b, q[i])}];
  int m = big, M = -big;
  each(_, e, mp) {
    chmin(m, e);
    chmax(M, e);
  }
  if (sz(mp) < (A + 1) * (B + 1)) m = 0;
  wt(m, M);
}
