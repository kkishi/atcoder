#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  map<int, map<int, bool>> g;
  rep(q) {
    ints(t, a, b);
    --a, --b;
    if (t == 1) g[a][b] = true;
    if (t == 2) g[a][b] = false;
    if (t == 3) wt(g[a][b] && g[b][a]);
  }
}
