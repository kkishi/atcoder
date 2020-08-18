#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct State {
  int r, c;
  int cost;
};

int main() {
  ints(h, w, k);
  ints(x1, y1, x2, y2);
  --x1, --y1, --x2, --y2;
  vector<string> grid(h);
  cin >> grid;

  State init = {x1, y1, 0};
  vector<vector<int>> seen(h, vector(w, -1));
  seen[x1][y1] = 0;
  queue<State> que;
  que.push(init);

  while (!que.empty()) {
    State here = que.front();
    dbg(here.r, here.c, here.cost);
    que.pop();
    if (here.r == x2 && here.c == y2) {
      wt(here.cost);
      return 0;
    }
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    rep(i, 4) {
      for (int j = 1; j <= k; ++j) {
        State there(here);
        there.r = here.r + dr[i] * j;
        there.c = here.c + dc[i] * j;
        there.cost++;
        if (there.r < 0 || h <= there.r || there.c < 0 || w <= there.c) {
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
