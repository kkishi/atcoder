#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  atcoder::mf_graph<int> g(h + w + 2);
  int s = h + w, t = s + 1;
  int sum = 0;
  rep(i, h) rep(j, w) {
    int x = a[i][j];
    if (x > 0) sum += x * 2;
    int r = i;
    int c = h + j;
    if (x >= 0) {
      g.add_edge(s, r, x);
      g.add_edge(r, c, x);
      g.add_edge(c, t, x);
    } else {
      g.add_edge(s, c, -x);
      g.add_edge(r, c, big);
      g.add_edge(r, t, -x);
    }
  }
  wt(sum - g.flow(s, t));
}
