#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<pair<int, int>, int> ps;
  map<int, int> hs, vs;
  map<int, V<int>> cs;
  set<int> rs;
  rep(n) {
    ints(r, c, x);
    ps[{r, c}] = x;
    hs[r] += x;
    vs[c] += x;
    cs[r].eb(c);
    rs.insert(r);
  }
  multiset<int> vss;
  each(_, e, vs) vss.insert(e);
  int ans = 0;
  each(r, rs) {
    V<int> rem;
    each(c, cs[r]) {
      chmax(ans, hs[r] + vs[c] - ps[{r, c}]);
      rem.eb(vs[c]);
      vss.erase(vss.find(vs[c]));
    }
    if (sz(vss) > 0) {
      chmax(ans, *prev(vss.end()) + hs[r]);
    }
    each(e, rem) vss.insert(e);
  }
  wt(ans);
}
