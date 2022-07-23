#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, c);
  V<int> t(n), a(n);
  rep(i, n) cin >> t[i] >> a[i];
  auto sol = [&](int c, const V<int>& t, const V<int>& a) -> V<int> {
    int cons = -1;
    int xors = 0;
    V<int> ret;
    rep(i, n) {
      if (t[i] == 1) {
        if (a[i] == 0) {
          cons = 0;
          xors = 0;
        }
      } else if (t[i] == 2) {
        if (a[i] == 1) {
          cons = 1;
          xors = 0;
        }
      } else {
        if (a[i] == 1) {
          xors = 1 - xors;
        }
      }
      if (cons != -1) c = cons;
      if (xors) c = 1 - c;
      ret.pb(c);
    }
    return ret;
  };
  VV<int> ans;
  rep(i, 30) {
    V<int> ai;
    rep(j, n) ai.pb(hasbit(a[j], i));
    ans.eb(sol(hasbit(c, i), t, ai));
  }
  rep(i, n) {
    int x = 0;
    rep(j, 30) x |= (ans[j][i] << j);
    wt(x);
  }
}
