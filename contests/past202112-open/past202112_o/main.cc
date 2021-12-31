#include <bits/stdc++.h>

#include <atcoder/convolution>
#include <atcoder/modint>

#include "atcoder.h"

using mint = atcoder::modint998244353;

void Main() {
  ints(n);
  const int N = 100000;
  V<mint> a(N);
  rep(n) {
    ints(b);
    ++a[b - 1];
  }
  V<mint> c(a.rbegin(), a.rend());
  V<mint> b = atcoder::convolution(a, c);
  V<int> s(n);
  cin >> s;
  mint ans = 0;
  rep(k, 1, n) {
    mint v = b[N - 1 - k];
    ans += (n - k) * v * s[k - 1];
  }
  rep(i, n - 2) ans *= i + 1;
  wt(ans.val());
}
