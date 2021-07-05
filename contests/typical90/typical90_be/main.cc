#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

VV<int> GaussJordan(VV<int> v) {
  int n = sz(v), m = sz(v[0]);
  int rank = 0;
  rep(col, m) {
    int pivot = -1;
    rep(row, rank, n) if (v[row][col] != 0) {
      pivot = row;
      break;
    }
    if (pivot != -1) {
      if (pivot != rank) swap(v[rank], v[pivot]);
      rep(row, n) if (row != rank && v[row][col] != 0) {
        rep(c, col, m) v[row][c] ^= v[rank][c];
      }
      ++rank;
    }
  }
  return v;
}

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  vector v(n, vector(m, int(0)));
  rep(i, n) {
    ints(t);
    rep(t) {
      ints(a);
      v[i][a - 1] = 1;
    }
  }
  V<int> s(m);
  cin >> s;

  vector w = GaussJordan(v);
  rep(i, m) if (s[i] == 1) rep(j, n) if (w[j][i] == 1) rep(k, m) s[k] ^=
      w[j][k];
  if (s == V<int>(m, 0)) {
    int zero = 0;
    rep(i, n) if (w[i] == V<int>(m, 0))++ zero;
    wt(mint(2).Pow(zero));
  } else {
    wt(0);
  }
}
