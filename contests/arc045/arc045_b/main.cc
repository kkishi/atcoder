#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  int N = 300000;
  VV<int> add(N + 2), del(N + 2);
  rep(i, m) {
    ints(s, t);
    add[s].pb(i);
    del[t + 1].pb(i);
  }
  set<int> s;
  set<int> ng;
  rep(i, N + 2) {
    each(e, add[i]) s.insert(e);
    each(e, del[i]) s.erase(e);
    if (sz(s) == 1) {
      ng.insert(*s.begin());
    }
  }
  wt(m - sz(ng));
  rep(i, m) if (!ng.count(i)) wt(i + 1);
}
