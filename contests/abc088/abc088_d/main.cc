#include <bits/stdc++.h>

#include "atcoder.h"
#include "grid.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;

  Grid<int> g(h, w);
  rep(i, h) rep(j, w) if (s[i][j] != '#') g.Set(i, j, 1);
  optional<int> d = g.Distance(0, 0)[h - 1][w - 1];
  if (!d) {
    wt(-1);
  } else {
    int black = 0;
    rep(i, h) black += count(all(s[i]), '#');
    wt(h * w - black - *d - 1);
  }
}
