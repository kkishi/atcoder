#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, l, k);
  V<int> v;
  int pa = 0;
  rep(n) {
    ints(a);
    v.pb(a - pa);
    pa = a;
  }
  v.pb(l - pa);
  wt(BinarySearch<int>(0, big, [&](int x) {
    int y = 0;
    int l = 0;
    rep(i, sz(v)) {
      l += v[i];
      if (l >= x) {
        l = 0;
        ++y;
      }
    }
    return y >= k + 1;
  }));
}
