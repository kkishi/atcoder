#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

void Main() {
  ints(n, K);
  if (K == 1) {
    wt("Infinity");
    return;
  }
  V<Point> p(n);
  cin >> p;

  int ans = 0;
  vector counted(n, vector(n, false));
  rep(i, n) rep(j, i) if (!counted[i][j]) {
    Line l = {p[i], p[j]};
    int cnt = 0;
    V<int> online;
    rep(k, n) if (Intersect(l, p[k])) {
      ++cnt;
      online.eb(k);
    }
    if (cnt >= K) {
      ++ans;
      each(e, online) each(f, online) counted[e][f] = true;
    }
  }
  wt(ans);
}
