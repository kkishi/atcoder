// This solution is based on: https://trap.jp/post/1594/ (Zobrist Hash)
#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"
#include "sieve.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  const int N = 1000000;
  vector h(N + 1, array<int, 3>());
  Rand r;
  rep(i, N + 1) rep(j, 1, 3) h[i][j] = r.Int(0, big);
  Sieve s(N);
  V<int> b(n + 1);
  V<int> c(N + 1);
  rep(i, n) {
    b[i + 1] = b[i];
    each(k, v, s.Factors(a[i])) {
      b[i + 1] ^= h[k][c[k]];
      c[k] += v;
      c[k] %= 3;
      b[i + 1] ^= h[k][c[k]];
    }
  }
  rep(q) {
    ints(l, r);
    wt(b[r] == b[l - 1]);
  }
}
