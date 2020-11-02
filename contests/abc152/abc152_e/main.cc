#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(N);
  V<int> A(N);
  cin >> A;
  map<int, int> m;
  rep(i, N) {
    map<int, int> fs = Factorize(A[i]);
    for (auto [k, v] : fs) {
      m[k] = max(m[k], v);
    }
  }
  mint lcm = 1;
  for (auto [k, v] : m) {
    rep(i, v) lcm *= k;
  }
  mint ans = 0;
  rep(i, N) ans += lcm / A[i];
  wt(ans);
}
