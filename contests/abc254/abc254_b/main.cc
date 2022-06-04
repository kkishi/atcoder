#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> v = {1};
  rep(n) {
    wt(v);
    V<int> nv;
    rep(i, sz(v) + 1) {
      int x = v[i];
      if (i > 0) x += v[i - 1];
      nv.pb(x);
    }
    swap(v, nv);
  }
}
