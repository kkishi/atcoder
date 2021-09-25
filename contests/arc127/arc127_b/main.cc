#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l);
  V<string> v;
  rep(i, n) {
    string s = "2" + string(l - 1, '0');
    int I = i;
    rrep(j, l) {
      if (I == 0) break;
      s[j] += I % 3;
      I /= 3;
    }
    v.eb(s);
  }
  rrep(i, 3) {
    each(e, v) wt(e);
    each(e, v) each(f, e) {
      ++f;
      if (f == '3') f = '0';
    }
  }
}
