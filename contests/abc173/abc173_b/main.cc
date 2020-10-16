#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<string, int> m;
  rep(i, n) {
    strings(s);
    m[s]++;
  }
  for (auto k : {"AC", "WA", "TLE", "RE"}) {
    wt(k, 'x', m[k]);
  }
}
