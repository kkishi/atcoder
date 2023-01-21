#include <bits/stdc++.h>

#include <atcoder/math>

#include "atcoder_interactive.h"

void Main() {
  V<long long> p = {4, 9, 5, 7, 11, 13, 17, 19, 23};
  int m = accumulate(p);
  wt_flush(m);

  int sum = 0;
  V<int> a;
  each(e, p) {
    rep(i, e) a.pb((i + 1) % e + sum + 1);
    sum += e;
  }
  wt_flush(a);

  V<int> b(m);
  cin >> b;

  int n = sz(p);
  V<long long> r(n);
  sum = 0;
  rep(i, n) {
    r[i] = b[sum] - (sum + 1);
    sum += p[i];
  }
  auto [y, z] = atcoder::crt(r, p);
  wt(y);
}
