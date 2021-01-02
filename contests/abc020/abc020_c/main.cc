#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "grid.h"

void Main() {
  ints(h, w, t);
  V<string> s(h);
  cin >> s;
  wt(BinarySearch<int>(1, big, [&](int x) {
    Grid<int> grid(h, w);
    int sr, sc, gr, gc;
    rep(i, h) rep(j, w) {
      if (s[i][j] == 'S') sr = i, sc = j;
      if (s[i][j] == 'G') gr = i, gc = j;
      grid.Set(i, j, s[i][j] == '#' ? x : 1);
    }
    optional<int> d = grid.Distance(sr, sc)[gr][gc];
    return d && d <= t;
  }));
}
