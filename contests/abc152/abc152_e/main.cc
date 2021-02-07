#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  rep(i, n) {
    for (auto [k, v] : Factors(a[i])) {
      chmax(m[k], v);
    }
  }
  mint lcm = 1;
  for (auto [k, v] : m) {
    rep(i, v) lcm *= k;
  }
  mint ans = 0;
  rep(i, n) ans += lcm / a[i];
  wt(ans);
}
