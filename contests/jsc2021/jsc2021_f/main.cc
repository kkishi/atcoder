#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"
#include "compressor.h"

void Main() {
  ints(n, m, q);
  V<int> len{n, m};
  V<int> t(q), x(q), y(q);
  rep(i, q) cin >> t[i] >> x[i] >> y[i];
  V<int> y_and_zero = y;
  y_and_zero.pb(0);
  Compressor cy(y_and_zero);
  const int N = sz(cy.coord);
  vector cnt(2, BIT<int>(N + 1));
  rep(i, 2) cnt[i].Set(0, len[i]);
  vector sum(2, BIT<int>(N + 1));
  vector val(2, V<int>(max(len[0], len[1])));
  int s = 0;
  rep(i, q) {
    int A = 0, B = 1;
    if (t[i] == 2) swap(A, B);
    int I = x[i] - 1;
    int Ya = val[A][I];
    int Yb = y[i];
    val[A][I] = Yb;
    int Ia = cy(Ya);
    cnt[A].Add(Ia, -1);
    sum[A].Add(Ia, -Ya);
    int Ib = cy(Yb);
    cnt[A].Add(Ib, 1);
    sum[A].Add(Ib, Yb);
    s -= cnt[B].Sum(Ia) * Ya;
    s += sum[B].Sum(Ia);
    s -= sum[B].Sum(Ib);
    s += cnt[B].Sum(Ib) * Yb;
    wt(s);
  }
}
