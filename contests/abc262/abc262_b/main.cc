#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector g(n, vector(n, false));
  rep(m) {
    ints(u, v);
    --u, --v;
    g[u][v] = g[v][u] = true;
  }
  int ans = 0;
  rep(c, n) rep(b, c) rep(a, b) {
    if (g[a][b] && g[b][c] && g[c][a]) ++ans;
  }
  wt(ans);
}
