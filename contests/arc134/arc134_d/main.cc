#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n * 2);
  cin >> a;
  int mi_f = big;
  rep(i, n) chmin(mi_f, a[i]);
  int mi_b = big;
  rep(i, n) if (a[i] == mi_f) chmin(mi_b, a[i + n]);
  if (mi_f >= mi_b) {
    wt(mi_f, mi_b);
    return;
  }
  map<int, V<int>> M;
  rep(i, n) M[a[i]].pb(i);
  V<int> F, B;
  int idx;
  rep(i, n) if (a[i] == mi_f) {
    F.pb(a[i]);
    B.pb(a[i + n]);
    idx = i + 1;
  }
  bool x = false;
  rep(i, 1, sz(B)) {
    if (B[i] != B[i - 1]) {
      x = B[i] > B[i - 1];
      break;
    }
  }
  each(k, v, M) {
    if (k > B[0] || (k == B[0] && !x)) {
      break;
    }
    each(e, v) if (e >= idx) {
      F.pb(a[e]);
      B.pb(a[n + e]);
      idx = e + 1;
    }
  }
  each(e, B) F.pb(e);
  wt(F);
}
