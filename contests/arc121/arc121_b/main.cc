#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  const int N = n * 2;
  V<int> a(N);
  V<char> c(N);
  rep(i, N) cin >> a[i] >> c[i];
  dbg(a);
  dbg(c);
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
    sort(all(ve));
    if (even(v)) {
      evens = ve;
    } else {
      odds.pb(ve);
    }
  }
  int ans = big;
  // odd, odd
  if (!odds[0].empty() && !odds[1].empty()) {
    each(e, odds[0]) {
      auto it = lower_bound(all(odds[1]), e);
      if (it != odds[1].end()) {
        chmin(ans, *it - e);
      }
      if (it != odds[1].begin()) {
        chmin(ans, e - *prev(it));
      }
    }
  }
  // (odd , even), (odd, even)
  if (sz(evens) >= 2) {
    VV<pair<int, int>> best(2);
    rep(i, 2) {
      each(e, odds[i]) {
        auto it = lower_bound(all(evens), e);
        int idx = it - evens.begin();
        rep(diff, -1, 2) {
          int I = idx + diff;
          if (0 <= I && I < sz(evens)) {
            best[i].eb(abs(evens[I] - e), I);
          }
        }
      }
      sort(all(best[i]));
    }
    dbg(best);
    if (best[0][0].second != best[1][0].second) {
      chmin(ans, best[0][0].first + best[1][0].first);
    } else {
      chmin(ans, best[0][1].first + best[1][0].first);
      chmin(ans, best[0][0].first + best[1][1].first);
    }
  }
  wt(ans);
}
