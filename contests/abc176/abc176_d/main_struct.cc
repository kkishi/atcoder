#include <bits/stdc++.h>

#include "atcoder.h"

int dp[1000][1000];

struct State {
  int r, c, warp;
  bool operator<(const State& s) const { return warp > s.warp; }
  int& ref() { return dp[r][c]; };
};

void Main() {
  ints(h, w);
  ints(ch, cw);
  --ch, --cw;
  ints(dh, dw);
  --dh, --dw;
  V<string> s(h);
  cin >> s;

  auto valid = [&](int r, int c) {
    return inside(r, c, h, w) && s[r][c] == '.';
  };

  rep(i, h) rep(j, w) dp[i][j] = big;

  State init = {ch, cw, 0};
  init.ref() = 0;

  priority_queue<State> que;
  que.push(init);

  while (!que.empty()) {
    State here = que.top();
    que.pop();
    if (here.r == dh && here.c == dw) {
      wt(here.warp);
      return;
    }
    each(nr, nc, adjacent(here.r, here.c)) {
      State there = here;
      there.r = nr;
      there.c = nc;
      if (!valid(there.r, there.c)) continue;
      if (there.ref() <= there.warp) continue;
      there.ref() = there.warp;
      que.push(there);
    }
    rep(dr, -2, 3) rep(dc, -2, 3) {
      State there = here;
      there.r += dr;
      there.c += dc;
      if (!valid(there.r, there.c)) continue;
      there.warp += 1;
      if (there.ref() <= there.warp) continue;
      there.ref() = there.warp;
      que.push(there);
    }
  }
  wt(-1);
}
