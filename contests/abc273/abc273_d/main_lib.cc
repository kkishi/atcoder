#include <bits/stdc++.h>

#include "atcoder.h"
#include "sparse_grid.h"

void Main() {
  ints(h, w, r, c);
  --r, --c;
  ints(n);
  SparseGrid g(h, w);
  rep(n) {
    ints(r, c);
    g.Insert(r - 1, c - 1);
  }
  ints(q);
  rep(q) {
    rd(char, d);
    ints(l);
    if (d == 'L') c = max(c - l, g.Left(r, c) + 1);
    if (d == 'R') c = min(c + l, g.Right(r, c) - 1);
    if (d == 'U') r = max(r - l, g.Up(r, c) + 1);
    if (d == 'D') r = min(r + l, g.Down(r, c) - 1);
    wt(r + 1, c + 1);
  }
}
