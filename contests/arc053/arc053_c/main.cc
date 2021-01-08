#include <bits/stdc++.h>

#include "atcoder.h"

void Reverse(V<pair<int, int>>& v) {
  reverse(all(v));
  rep(i, sz(v)) swap(v[i].first, v[i].second);
}
void Sort(V<pair<int, int>>& v) { sort(all(v)); }

void Main() {
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  V<pair<int, int>> neg, same, pos;
  rep(i, n) {
    ((a[i] < b[i]) ? neg : (a[i] == b[i]) ? same : pos)
        .eb(a[i], b[i]);
  }
  V<pair<int, int>> ans;
  Sort(neg);
  copy(all(neg), back_inserter(ans));
  copy(all(same), back_inserter(ans));
  Reverse(pos);
  Sort(pos);
  Reverse(pos);
  copy(all(pos), back_inserter(ans));
  int h = 0;
  int maxi = 0;
  for (auto [a, b] : ans) {
    h += a;
    chmax(maxi, h);
    h -= b;
  }
  wt(maxi);
}
