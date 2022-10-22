#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra_map.h"
#include "sparse_grid.h"

void Main() {
  ints(h, w, n);
  ints(sx, sy, gx, gy);
  --sx, --sy, --gx, --gy;
  SparseGrid grid(h, w);
  rep(n) {
    ints(x, y);
    --x, --y;
    grid.Insert(x, y);
  }
  using S = pair<int, int>;
  auto dist = Dijkstra<S, int>({sx, sy}, [&](S s, auto push) {
    auto [x, y] = s;
    if (int ny = grid.Left(x, y); ny >= 0) push({x, ny + 1}, 1);
    if (int ny = grid.Right(x, y); ny < w) push({x, ny - 1}, 1);
    if (int nx = grid.Up(x, y); nx >= 0) push({nx + 1, y}, 1);
    if (int nx = grid.Down(x, y); nx < h) push({nx - 1, y}, 1);
  });
  S g = {gx, gy};
  if (dist.count(g)) {
    wt(dist[g]);
  } else {
    wt(-1);
  }
}
