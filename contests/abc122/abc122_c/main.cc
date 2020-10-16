#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  strings(s);
  vector<int> cum(n);
  rep(i, 1, s.size()) {
    cum[i] = cum[i - 1];
    if (s[i - 1] == 'A' && s[i] == 'C') ++cum[i];
  }
  rep(q) {
    ints(l, r);
    wt(cum[r - 1] - cum[l - 1]);
  }
}
