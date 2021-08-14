#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

mint Naive(const V<int>& p, const V<int>& q) {
  int n = sz(p);
  V<int> r(n);
  rep(i, n) r[i] = i + 1;
  mint ans = 0;
  do {
    bool ok = true;
    rep(i, n) {
      if (r[i] == p[i] || r[i] == q[i]) ok = false;
    }
    if (ok) ++ans;
  } while (next_permutation(all(r)));
  return ans;
}

void Main() {
  ints(n);
  V<int> p(n), q(n);
  cin >> p >> q;
  wt(Naive(p, q));
}
