#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l);
  V<string> v;
  rep(i, n) {
    int I = i;
    string s;
    while (I) {
      s += '0' + I % 3;
      I /= 3;
    }
    reverse(all(s));
    v.eb(string(l - 1 - sz(s), '0') + s);
  }
  rrep(i, 3) {
    each(e, v) {
      cout << i;
      wt(e);
    }
    each(e, v) each(f, e) {
      ++f;
      if (f == '3') f = '0';
    }
  }
}
