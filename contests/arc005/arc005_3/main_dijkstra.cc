#include <bits/stdc++.h>

#include "atcoder.h"
#include "grid.h"

void Main() {
  ints(h, w);
  V<string> c(h);
  cin >> c;
  Grid<int> g(h, w);
  int sr, sc, gr, gc;
  rep(i, h) rep(j, w) {
    char x = c[i][j];
    if (x == 's') sr = i, sc = j;
    if (x == 'g') gr = i, gc = j;
    g.Set(i, j, x == '#');
  }
  wt(*g.Distance(sr, sc)[gr][gc] <= 2 ? "YES" : "NO");
}
