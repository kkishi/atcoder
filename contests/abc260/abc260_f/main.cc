#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(s, t, m);
  Graph g(s + t);
  g.Read(m);
  vector v(t, vector(t, int(-1)));
  rep(i, s) each(e, g[i]) each(f, g[i]) if (e != f) {
    int& x = v[e - s][f - s];
    if (x != -1) {
      wt(i + 1, x + 1, e + 1, f + 1);
      return;
    }
    x = i;
  }
  wt(-1);
}
