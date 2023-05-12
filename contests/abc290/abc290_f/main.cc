#include <bits/stdc++.h>

#include <atcoder/convolution>
#include <atcoder/modint>

#include "atcoder.h"

using mint = atcoder::modint998244353;

ostream& operator<<(ostream& os, mint x) {
  os << x.val();
  return os;
}

void Main() {
  const int N = 1000000;
  V<mint> fact(N + 1, 1);
  rep(i, 1, N + 1) fact[i] = fact[i - 1] * i;
  V<mint> inv(N + 1, 1);
  rep(i, 2, N + 1) inv[i] = mint::mod() / i * -inv[mint::mod() % i];
  V<mint> ifact(N + 1, 1);
  rep(i, 2, N + 1) ifact[i] = ifact[i - 1] * inv[i];

  V<mint> f(N + 1, 1);
  rep(i, 3, N + 1) f[i] = fact[i] * fact[i - 3];
  V<mint> g(N + 1);
  rep(i, 1, N + 1) g[i] = (i + 1) * ifact[i] * ifact[i - 1];
  V<mint> h(N + 1);
  rep(i, 2, N + 1) h[i] = ifact[i] * ifact[i - 2];

  V<mint> e = convolution(g, h);

  ints(t);
  rep(t) {
    ints(n);
    if (n == 2) {
      wt(1);
    } else {
      wt((f[n] * e[n]).val());
    }
  }
}
