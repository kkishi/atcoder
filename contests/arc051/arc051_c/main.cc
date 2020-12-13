#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(N, A, B);
  V<int> a(N);
  cin >> a;

  if (A == 1) {
    sort(all(a));
    rep(i, N) wt(a[i]);
    return;
  }

  multiset<int> s(all(a));
  while (B > 0 && *s.begin() * A < *prev(s.end())) {
    auto it = s.begin();
    s.erase(it);
    s.insert(*it * A);
    --B;
  }

  mint p = mint(A).Pow(B / N);
  V<mint> b(all(s));
  rep(i, N) b[i] *= p;
  rep(i, B % N, N) wt(b[i]);
  rep(i, B % N) wt(b[i] * A);
}
