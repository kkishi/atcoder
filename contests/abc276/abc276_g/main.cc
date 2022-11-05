#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  if (m < n - 1) {
    wt(0);
    return;
  }
  // let f(x) = C(n-1, x)
  // sum[i] = f(0) + f(1) + ... + f(i)
  V<mint> sum(m + 1);
  rep(i, sz(sum)) {
    if (i > 0) sum[i] = sum[i - 1];
    sum[i] += mint::Comb(n - 1, i);
  }
  // sum2[i] = (i+1)*f(0) + i*f(1) + ... + f(i)
  V<mint> sum2(m + 1);
  rep(i, sz(sum2)) {
    if (i > 0) sum2[i] = sum2[i - 1];
    sum2[i] += sum[i];
  }
  int rem = m - (n - 1);
  mint ans = 0;
  rep(x, (rem / 3) + 1) {
    mint a = mint::Comb(x + n - 2, n - 2);  // H(n - 1, x)
    mint b = sum2[rem - x * 3];
    ans += a * b;
  }
  wt(ans);
}
