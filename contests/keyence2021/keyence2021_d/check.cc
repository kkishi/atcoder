#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  VV<int> same;
  int l = 0;
  rep(k) {
    strings(s);
    if (l == 0) {
      l = sz(s);
      same = vector(l, vector(l, int(0)));
    }
    rep(i, l - 1) rep(j, i + 1, l) if (s[i] == s[j])++ same[i][j];
  }
  dbg(l);
  rep(i, l) dbg(same[i]);
  rep(i, l - 1) rep(j, i + 1, l) assert(same[i][j] == same[0][1]);
}
