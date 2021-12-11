#include <bits/stdc++.h>

#include <atcoder/convolution>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  using ll = long long;
  const int N = 100000;
  V<ll> a(N);
  rep(n) {
    ints(b);
    ++a[b - 1];
  }
  V<ll> c(a.rbegin(), a.rend());
  V<ll> b = atcoder::convolution(a, c);
  V<int> s(n);
  cin >> s;
  mint ans = 0;
  rep(k, 1, n) {
    int v = b[N - 1 - k];
    ans += (n - k) * v * s[k - 1];
  }
  wt(ans * mint::Fact(n - 2));
}
