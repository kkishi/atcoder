#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"
#include "compressor.h"

void Main() {
  ints(n);
  V<pair<int, int>> v(n);
  rep(i, n) cin >> v[i].first;
  rep(i, n) cin >> v[i].second;
  V<int> val;
  each(x, y, v) {
    val.pb(x);
    val.pb(y);
  }
  Compressor cmp(val);
  int N = sz(cmp.coord);
  sort(all(v));
  BIT<int> bit(N);
  int ans = 0;
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && v[i].first == v[j].first) ++j;
    rep(k, i, j) {
      auto [a, b] = v[k];
      bit.Add(cmp(b), 1);
    }
    rep(k, i, j) {
      auto [a, b] = v[k];
      ans += bit.Sum(N - 1) - bit.Sum(cmp(b) - 1);
    }
    i = j;
  }
  wt(ans);
}
