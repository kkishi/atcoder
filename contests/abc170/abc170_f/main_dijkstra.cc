#include <bits/stdc++.h>

#include "atcoder.h"

struct Position {
  int r, c, dir;
  bool operator<(const Position& p) const {
    if (r != p.r) return r < p.r;
    if (c != p.c) return c < p.c;
    return dir < p.dir;
  }
};

struct Cost {
  int strokes;
  int dist;
  bool operator<(const Cost& c) const {
    if (strokes != c.strokes) return strokes < c.strokes;
    return dist < c.dist;
  }
};

struct State {
  Position position;
  Cost cost;
  bool operator<(const State& s) const { return s.cost < cost; }
};

const int INF = 1 << 30;

void Main() {
  ints(h, w, k);
  ints(x1, y1, x2, y2);
  --x1, --y1, --x2, --y2;
  vector<string> grid(h);
  cin >> grid;

  vector cost(h, vector(w, vector(4, Cost{INF, INF})));
  auto CostOf = [&](const Position& p) -> Cost& {
    return cost[p.r][p.c][p.dir];
  };
  priority_queue<State> que;
  auto push = [&](const State& s) {
    Cost& c = CostOf(s.position);
    if (!(s.cost < c)) return;
    c = s.cost;
    que.push(s);
  };
  rep(dir, 4) push(State{{x1, y1, dir}, {1, 0}});
  while (!que.empty()) {
    State here = que.top();
    que.pop();
    if (here.position.r == x2 && here.position.c == y2) {
      wt(here.cost.strokes);
      return;
    }
    {
      int dr[] = {1, -1, 0, 0};
      int dc[] = {0, 0, 1, -1};
      State there(here);
      there.position.r += dr[there.position.dir];
      there.position.c += dc[there.position.dir];
      if (there.cost.dist < k) {
        ++there.cost.dist;
      } else {
        ++there.cost.strokes;
        there.cost.dist = 1;
      }
      if (int r = there.position.r, c = there.position.c;
          inside(r, c, h, w) && grid[r][c] == '.') {
        push(there);
      }
    }
    rep(i, 4) {
      State there(here);
      there.position.dir = i;
      ++there.cost.strokes;
      there.cost.dist = 0;
      push(there);
    }
  }
  wt(-1);
}
