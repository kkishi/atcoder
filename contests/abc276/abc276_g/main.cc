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
  // step 1: sum[i] = f(i)
  // step 2: sum[i] = f(0) + f(1) + ... + f(i)
  // step 3: sum[i] = (i+1)*f(0) + i*f(1) + ... + f(i)
  V<mint> sum(m + 1);
  rep(i, m + 1) sum[i] = mint::Comb(n - 1, i);
  rep(2) rep(i, 1, m + 1) sum[i] += sum[i - 1];
  int rem = m - (n - 1);
  mint ans = 0;
  rep(x, (rem / 3) + 1) {
    mint a = mint::Comb(x + n - 2, n - 2);  // H(n - 1, x)
    mint b = sum[rem - x * 3];
    ans += a * b;
  }
  wt(ans);
}
