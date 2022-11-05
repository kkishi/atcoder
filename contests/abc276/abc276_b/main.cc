#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph g(n);
  g.Read(m);
  each(e, g) {
    V<int> ans;
    ans.eb(sz(e));
    sort(e);
    each(e, e) ans.eb(e + 1);
    wt(ans);
  }
}
