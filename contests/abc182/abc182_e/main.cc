#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "bit.h"

struct State {
  bool object;
  bool lit;
};

void Main() {
  ints(h, w, n, m);
  V<pair<int, int>> bulbs;
  rep(n) {
    ints(a, b);
    bulbs.eb(a - 1, b - 1);
  }
  V<pair<int, int>> blocks;
  rep(m) {
    ints(c, d);
    blocks.eb(c - 1, d - 1);
  }
  vector grid(h, vector(w, State{false, false}));
  for (auto [r, c] : bulbs) {
    grid[r][c].object = true;
  }
  for (auto [r, c] : blocks) {
    grid[r][c].object = true;
  }
  int ans = 0;
  for (auto [r, c] : bulbs) {
    each(dr, dc, adjacent(0, 0)) {
      for (int i = 1;; ++i) {
        int nr = r + dr * i;
        int nc = c + dc * i;
        if (!inside(nr, nc, h, w)) break;
        if (grid[nr][nc].object) break;
        if (!grid[nr][nc].lit) {
          grid[nr][nc].lit = true;
          ++ans;
        }
      }
    }
    ++ans;
  }
  wt(ans);
}
