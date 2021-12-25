#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> v(n);
  cin >> v;
  sort(all(v), [](auto& a, auto& b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first > b.first;
  });
  V<int> L(n);
  {
    int l = -big, r = big;
    rep(i, n) {
      chmax(l, v[i].first);
      chmin(r, v[i].second);
      L[i] = max(0, r - l + 1);
    }
  }
  V<int> R(n);
  {
    int l = -big, r = big;
    rrep(i, n) {
      chmax(l, v[i].first);
      chmin(r, v[i].second);
      R[i] = max(0, r - l + 1);
    }
  }
  int ans = -big;
  rep(i, n - 1) chmax(ans, L[i] + R[i + 1]);
  {
    multiset<int> L, R;
    each(l, r, v) {
      L.insert(l);
      R.insert(r);
    }
    each(l, r, v) {
      L.erase(L.find(l));
      R.erase(R.find(r));
      chmax(ans, r - l + 1 + max(0, *R.begin() - *prev(L.end()) + 1));
      L.insert(l);
      R.insert(r);
    }
  }
  wt(ans);
}
