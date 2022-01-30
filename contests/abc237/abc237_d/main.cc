#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  V<int> f, b;
  int x = 0;
  rep(i, n) {
    if (s[i] == 'L') {
      b.pb(x);
    } else {
      f.pb(x);
    }
    x = i + 1;
  }
  f.eb(x);
  reverse(all(b));
  each(e, b) f.eb(e);
  wt(f);
}
