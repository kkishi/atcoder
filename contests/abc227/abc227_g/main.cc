#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  map<int, int> cnt;

  V<int> p(k);
  rep(i, k) p[i] = n - i;
  for (int i = 2; i * i <= n; ++i) {
    for (int j = div_ceil(n - k + 1, i) * i; j <= n; j += i) {
      int d = n - j;
      while (p[d] % i == 0) {
        p[d] /= i;
        ++cnt[i];
      }
    }
  }
  each(e, p)++ cnt[e];

  V<int> l(k);
  rep(i, k) l[i] = k - i;
  for (int i = 2; i * i <= k; ++i) {
    for (int j = i; j <= k; j += i) {
      int d = k - j;
      while (l[d] % i == 0) {
        l[d] /= i;
        --cnt[i];
      }
    }
  }
  each(e, l)-- cnt[e];

  mint ans = 1;
  cnt.erase(1);
  each(k, v, cnt) ans *= v + 1;
  wt(ans);
}
