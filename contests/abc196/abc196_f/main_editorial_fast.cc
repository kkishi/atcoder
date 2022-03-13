#include <bits/stdc++.h>

#include <atcoder/convolution>
#include <atcoder/modint>

#include "atcoder.h"

void Main() {
  strings(s, t);
  V<int> a;
  each(e, s) a.eb(e == '0' ? 1 : -1);
  V<int> b;
  each(e, t) b.eb(e == '0' ? 1 : -1);
  reverse(b);
  V<int> c = atcoder::convolution(b, a);
  int ans = big;
  rep(i, sz(t) - 1, sz(c) - sz(t) + 1) {
    // Convolution is computed with mod 998244353. We use negative values and
    // divisions, so we need to reconstruct the original value.
    chmin(ans, sz(t) - ((atcoder::modint998244353(c[i]) + sz(t)) / 2).val());
  }
  wt(ans);
}
