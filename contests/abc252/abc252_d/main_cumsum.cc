#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> mp;
  each(e, a)++ mp[e];
  V<int> v;
  each(_, e, mp) v.eb(e);

  int N = sz(v);
  V<int> f(N + 1), b(N + 1);
  rep(i, N) f[i + 1] = f[i] + v[i];
  rrep(i, N) b[i] = b[i + 1] + v[i];

  int ans = 0;
  rep(i, 1, N - 1) ans += f[i] * v[i] * b[i + 1];
  wt(ans);
}
