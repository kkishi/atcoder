#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  map<int, int> M;
  rep(n) {
    ints(a);
    ++M[a];
  }
  rep(m) {
    ints(b);
    ++M[b];
  }
  V<int> ans;
  each(k, v, M) if (v == 1) ans.pb(k);
  wt(ans);
}
