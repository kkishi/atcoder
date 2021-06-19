#include <bits/stdc++.h>

#include "atcoder.h"
#include "sieve.h"

Sieve sieve(1e6 + 1);

void Main() {
  ints(l, r);
  int ans = 0;
  rep(x, max(2, l), r + 1) {
    V<int> v;
    each(k, _, sieve.Factors(x)) v.pb(k);
    int C = 0;
    rep(mask, 1, 1 << sz(v)) {
      int p = 1;
      rep(i, sz(v)) if (hasbit(mask, i)) p *= v[i];
      int H = r / p;
      int L = x / p;
      if (L > H) continue;
      int c = H - L;
      if (even(popcount(mask))) c = -c;
      C += c;
    }
    int all = r - x;
    int A = all - C;
    int B = r / x - 1;
    ans += all - (A + B);
  }
  wt(ans * 2);
}
