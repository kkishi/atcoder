#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> v;
  while (x) {
    v.pb(x % 2);
    x /= 2;
  }
  reverse(all(v));
  strings(s);
  each(e, s) {
    if (e == 'U') {
      v.pop_back();
    } else if (e == 'L') {
      v.push_back(0);
    } else {
      v.push_back(1);
    }
  }
  x = 0;
  rep(i, sz(v)) {
    x *= 2;
    x += v[i];
  }
  wt(x);
}
