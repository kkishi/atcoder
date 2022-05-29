#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(w);
  V<int> a;
  rep(i, 1, 101) {
    a.pb(i);
    a.pb(i * 100);
    a.pb(i * 10000);
  }
  wt(sz(a));
  wt(a);
}
