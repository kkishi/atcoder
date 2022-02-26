#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  int L = 55;
  vector v(L, vector(n, pair<int, int>()));
  rep(i, n) v[0][i] = {(i + a[i]) % n, a[i]};
  rep(i, 1, L) rep(j, n) {
    auto [I, J] = v[i - 1][j];
    auto [K, L] = v[i - 1][I];
    v[i][j] = {K, J + L};
  }
  int I = 0, J = 0;
  rep(i, L) if (hasbit(k, i)) {
    auto [K, L] = v[i][I];
    J += L;
    I = K;
  }
  wt(J);
}
