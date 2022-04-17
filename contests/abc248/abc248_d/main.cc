#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  ints(q);
  VV<pair<int, int>> QL(n), QR(n);
  rep(i, q) {
    ints(l, r, x);
    --l;
    --r;
    QL[l].eb(x, i);
    QR[r].eb(x, i);
  }
  V<int> ql(q), qr(q);
  vector cnt(200001, int(0));
  rep(I, n) {
    each(x, i, QL[I]) ql[i] = cnt[x];
    ++cnt[a[I]];
    each(x, i, QR[I]) qr[i] = cnt[x];
  }
  rep(i, q) wt(qr[i] - ql[i]);
}
