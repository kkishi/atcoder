#include <bits/stdc++.h>
#include <min_cost_flow.h>

#include "atcoder.h"

void Main() {
  ints(h, w, n);
  int s = h + w, t = s + 1;

  MinCostFlow g;
  rep(i, h) g.Add(s, i, big, 0, 1);
  rep(i, w) g.Add(h + i, t, big, 0, 1);
  rep(n) {
    ints(a, b, c);
    --a, --b;
    g.Add(a, h + b, 1, c);
  }
  wt(g.Flow(s, t).second);
}
