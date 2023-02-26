#include <bits/stdc++.h>

#include <atcoder/convolution>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> s(n), t(n);
  cin >> s >> t;
  V<int> d(n * 3);
  rep(bit, 5) {
    V<int> a;
    rep(2) each(e, s) a.eb(!hasbit(e, bit));
    V<int> b;
    each(e, t) b.eb(!hasbit(e, bit));
    reverse(all(b));
    V<int> c = atcoder::convolution(b, a);
    rep(i, sz(t) - 1, sz(c) - sz(t) + 1) {
      d[i - (sz(t) - 1)] += (n - c[i]) << bit;
    }
  }
  wt(*max_element(all(d)));
}
