#include <bits/stdc++.h>

#include "atcoder.h"
#include "sieve.h"

void Main() {
  ints(n);
  Sieve s(200000);
  map<V<int>, int> mp;
  rep(i, 1, n + 1) {
    V<int> key;
    each(k, v, s.Factors(i)) if (!even(v)) key.eb(k);
    ++mp[key];
  }
  int ans = 0;
  each(_, e, mp) ans += e * e;
  wt(ans);
}
