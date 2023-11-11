#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  strings(s);
  V<int> c(n+1);
  rep(i, 1, n) {
    c[i] = c[i-1] + (s[i-1] == s[i]);
  }
  rep(q) {
    ints(l, r);
    wt(c[r-1] - c[l-1]);
  }
}
