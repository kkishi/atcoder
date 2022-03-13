#include <bits/stdc++.h>

#include <atcoder/convolution>

#include "atcoder.h"

void Main() {
  strings(s, t);
  V<int> d(sz(s) - sz(t) + 1);
  rep(i, 2) {
    V<int> a;
    each(e, s) a.eb(e == ('0' + i));
    V<int> b;
    each(e, t) b.eb(e == ('0' + i));
    reverse(b);
    V<int> c = atcoder::convolution(b, a);
    rep(i, sz(t) - 1, sz(c) - sz(t) + 1) d[i - (sz(t) - 1)] += c[i];
  }
  wt(sz(t) - max(d));
}
