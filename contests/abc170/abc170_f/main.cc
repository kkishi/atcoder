#include <bits/stdc++.h>

#include "atcoder.h"

struct State {
  int r, c;
  int cost;
};

void Main() {
  ints(h, w, k);
  ints(x1, y1, x2, y2);
  --x1, --y1, --x2, --y2;
  vector<string> grid(h);
  cin >> grid;

  State init = {x1, y1, 0};
  vector seen(h, vector(w, -1L));
  seen[x1][y1] = 0;
  queue<State> que;
  que.push(init);

  while (!que.empty()) {
    State here = que.front();
    dbg(here.r, here.c, here.cost);
    que.pop();
    if (here.r == x2 && here.c == y2) {
      wt(here.cost);
      return;
    }
    each(dr, dc, adjacent(0, 0)) {
      rep(j, k) {
        State there(here);
        there.r = here.r + dr * (j + 1);
        there.c = here.c + dc * (j + 1);
        there.cost++;
        if (!inside(there.r, there.c, h, w)) {
          break;
        }
        if (grid[there.r][there.c] == '@') {
          break;
        }
        int& s = seen[there.r][there.c];
        if (s != -1 && s < there.cost) break;
        if (s != -1 && s <= there.cost) continue;
        s = there.cost;
        que.push(there);
      }
    }
  }
  wt(-1);
}
