#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  VV<int> a;
  rep(n) {
    ints(l);
    V<int> ai(l);
    cin >> ai;
    a.eb(ai);
  }
  rep(q) {
    ints(s, t);
    --s, --t;
    wt(a[s][t]);
  }
}
