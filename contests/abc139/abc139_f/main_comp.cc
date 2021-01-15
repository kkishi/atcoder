#include <bits/stdc++.h>

#include "atcoder.h"

using P = complex<double>;

void Main() {
  ints(n);
  V<P> p;
  rep(n) {
    ints(x, y);
    p.eb(x, y);
  }
  double ans = 0;
  each(pi, p) each(pj, p) {
    P q = pi + pj;
    P sum;
    each(pk, p) if ((pk / q).real() > 0) sum += pk;
    chmax(ans, abs(sum));
  }
  wt(ans);
}
