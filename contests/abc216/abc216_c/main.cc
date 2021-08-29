#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> b;
  while (n) {
    b.pb(n & 1);
    n /= 2;
  }
  string ans;
  rrep(i, sz(b)) {
    if (i < sz(b) - 1) ans += 'B';
    if (b[i]) ans += 'A';
  }
  wt(ans);
}
