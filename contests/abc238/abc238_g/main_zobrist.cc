#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"
#include "sieve.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  const int N = 1000000;
  const int M = 20;
  using i8 = int8_t;
  using H = array<i8, M>;
  Rand r;
  vector hash(N + 1, H());
  rep(i, N + 1) rep(j, M) hash[i][j] = r.Int(0, 2);
  H h = {};
  V<H> hs;
  hs.eb(h);
  Sieve s(N);
  rep(i, n) {
    each(k, v, s.Factors(a[i])) {
      rep(j, M) {
        h[j] += hash[k][j] * v;
        h[j] %= 3;
      }
    }
    hs.eb(h);
  }
  rep(q) {
    ints(l, r);
    wt(hs[r] == hs[l - 1]);
  }
}
