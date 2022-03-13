#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> b(n);
  cin >> b;
  sort(b);
  V<int> m(n);
  rep(i, n) rep(j, i + 1, n) {
    int d = b[j] - b[i];
    if (d >= n) break;
    ++m[d];
  }
  V<int> s(n);
  cin >> s;
  mint ans = 0;
  rep(k, 1, n) {
    int v = m[k];
    ans += (n - k) * v * s[k - 1];
  }
  wt(ans * mint::Fact(n - 2));
}
