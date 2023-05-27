#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  --k;
  V<int16_t> a(n);
  cin >> a;
  using P = pair<int16_t, int16_t>;
  V<P> v;
  rep(i, n) rep(j, i, n) v.eb(i, j);
  nth_element(v.begin(), v.begin() + k, v.end(), [&](const P& p, const P& q) {
    auto [pl, pr] = p;
    auto [ql, qr] = q;
    if (pl < ql) {
      if (pl == pr) return a[ql] < a[qr];
      return a[pr] < a[pl];
    }
    if (pl > ql) {
      if (ql == qr) return a[pr] < a[pl];
      return a[ql] < a[qr];
    }
    return a[pr] < a[qr];
  });
  auto [l, r] = v[k];
  reverse(a.begin() + l, a.begin() + r + 1);
  wt(a);
}
