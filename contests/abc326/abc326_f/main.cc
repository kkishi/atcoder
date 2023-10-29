#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y);
  V<int> a(n);
  cin >> a;
  VV<int> b(2);
  rep(i, n) b[i % 2].eb(a[i]);
  V<int> masks(2, -1);
  rep(i, 2) {
    V<int> l, h;
    int N = sz(b[i]);
    rep(j, N)(j < N / 2 ? l : h).eb(b[i][j]);
    auto mkst = [](const V<int>& v) {
      if (v.empty()) {
        return map<int, int>{{0, 0}};
      }
      map<int, int> mp;
      rep(mask, 1 << sz(v)) {
        int sum = 0;
        rep(i, sz(v)) sum += (hasbit(mask, i) ? 1 : -1) * v[i];
        mp[sum] = mask;
      }
      return mp;
    };
    map<int, int> lst = mkst(l);
    map<int, int> rst = mkst(h);
    each(lv, mask, lst) {
      int rv = (even(i) ? y : x) - lv;
      if (rst.count(rv)) {
        masks[i] = mask | (rst[rv] << sz(l));
        break;
      }
    }
  }
  if (min(masks) >= 0) {
    wt("Yes");
    int dir = 1;
    int X = 0, Y = 0;
    rep(i, n) {
      int bit = (masks[i % 2] >> (i / 2)) & 1;
      (even(i) ? Y : X) += (bit ? 1 : -1) * a[i];
      cout << ((dir ^ bit ^ even(i)) ? 'L' : 'R');
      dir = bit;
    }
    cout << endl;
    assert(X == x);
    assert(Y == y);
  } else {
    wt("No");
  }
}
