#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  V<int> v;
  rep(i, a, b + 1) v.pb(i);
  int ans = 0;
  rep(i, 1 << sz(v)) {
    bool ok = true;
    if (popcount(i) > 1) {
      rep(j, sz(v)) rep(k, j + 1, sz(v)) {
        if (hasbit(i, j) && hasbit(i, k) && gcd(v[j], v[k]) != 1) {
          dbg(i, v[j], v[k]);
          ok = false;
        }
      }
    }
    if (ok) {
      V<int> w;
      rep(j, sz(v)) if (hasbit(i, j)) w.pb(v[j]);
      dbg(w);
      ++ans;
    }
  }
  wt(ans);
}
