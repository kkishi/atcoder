#include <bits/stdc++.h>

#include "atcoder.h"

struct Position {
  int r, c, dir;
};

struct Cost {
  int strokes;
  int dist;
};

struct State {
  Position position;
  Cost cost;
};

void Main() {
  ints(h, w, k);
  ints(x1, y1, x2, y2);
  --x1, --y1, --x2, --y2;
  vector<string> grid(h);
  cin >> grid;

  vector visited(h, vector(w, vector(4, false)));
  deque<State> que;
  auto push = [&](const State& s, bool front) {
    const Position& p = s.position;
    if (visited[p.r][p.c][p.dir]) return;
    visited[p.r][p.c][p.dir] = true;
    if (front) {
      que.push_front(s);
    } else {
      que.pb(s);
    }
  };
  rep(dir, 4) push(State{{x1, y1, dir}, {1, 0}}, false);
  while (!que.empty()) {
    State here = que.front();
    que.pop_front();
    dbg(here.cost.strokes, here.cost.dist);
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
      bool front;
      if (there.cost.dist < k) {
        ++there.cost.dist;
        front = true;
      } else {
        ++there.cost.strokes;
        there.cost.dist = 1;
        front = false;
      }
      if (int r = there.position.r, c = there.position.c;
          inside(r, c, h, w) && grid[r][c] == '.') {
        push(there, front);
      }
    }
    rep(i, 4) {
      State there(here);
      there.position.dir = i;
      ++there.cost.strokes;
      there.cost.dist = 0;
      push(there, false);
    }
  }
  wt(-1);
}
