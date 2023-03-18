#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> g(h);
  cin >> g;
  int i = 0, j = 0;
  set<pair<int, int>> seen;
  seen.insert({i, j});
  while (true) {
    int ni = i, nj = j;
    char c = g[i][j];
    if (c == 'U') --ni;
    if (c == 'D') ++ni;
    if (c == 'L') --nj;
    if (c == 'R') ++nj;
    if (!inside(ni, nj, h, w)) {
      wt(i + 1, j + 1);
      return;
    }
    if (!seen.insert({ni, nj}).second) {
      wt(-1);
      return;
    }
    i = ni, j = nj;
  }
}
