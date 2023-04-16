#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<pair<int, int>, int> ps;
  map<int, int> hs, vs;
  rep(n) {
    ints(r, c, x);
    ps[{r, c}] = x;
    hs[r] += x;
    vs[c] += x;
  }
  V<pair<int, int>> VS;
  each(k, v, vs) VS.eb(v, k);
  sort(VS, greater{});
  int ans = 0;
  each(r, h, hs) {
    each(v, c, VS) {
      auto it = ps.find({r, c});
      chmax(ans, h + v - (it == ps.end() ? 0 : it->second));
      if (it == ps.end()) break;
    }
  }
  wt(ans);
}
