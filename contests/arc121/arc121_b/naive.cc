#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  const int N = n * 2;
  V<int> a(N);
  V<char> c(N);
  rep(i, N) cin >> a[i] >> c[i];
  map<char, int> cnt;
  rep(i, N)++ cnt[c[i]];
  dbg(cnt);
  V<char> odd;
  for (auto [k, v] : cnt)
    if (!even(v)) odd.pb(k);
  if (odd.empty()) {
    wt(0);
    return;
  }

  VV<int> odds;
  V<int> evens;
  for (auto [k, v] : cnt) {
    V<int> ve;
    rep(i, N) if (c[i] == k) ve.pb(a[i]);
    sort(ve);
    if (even(v)) {
      evens = ve;
    } else {
      odds.pb(ve);
    }
  }

  int ans = big;
  // odd, odd
  if (!odds[0].empty() && !odds[1].empty()) {
    rep(i, sz(odds[0])) rep(j, sz(odds[1])) {
      chmin(ans, abs(odds[0][i] - odds[1][j]));
    }
  }
  if (sz(evens) >= 2) {
    rep(i, sz(evens)) rep(j, sz(evens)) {
      if (i == j) continue;
      int a = big;
      rep(k, sz(odds[0])) chmin(a, abs(odds[0][k] - evens[i]));
      int b = big;
      rep(k, sz(odds[1])) chmin(b, abs(odds[1][k] - evens[j]));
      chmin(ans, a + b);
    }
  }
  wt(ans);
}
