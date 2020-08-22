#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(h, w);
  ints(ch, cw);
  --ch, --cw;
  ints(dh, dw);
  --dh, --dw;
  V<string> s(h);
  cin >> s;

  map<pair<int, int>, int> seen;
  low_priority_queue<tuple<int, int, int>> que;

  auto push = [&](int r, int c, int warp) {
    if (r < 0 || h <= r || c < 0 || w <= c || s[r][c] == '#') return;
    auto [it, ok] = seen.insert({{r, c}, warp});
    if (!ok && warp >= it->second) return;
    it->second = warp;
    que.push({warp, r, c});
  };
  push(ch, cw, 0);

  while (!que.empty()) {
    auto [warp, r, c] = que.top();
    que.pop();
    if (r == dh && c == dw) {
      wt(warp);
      return 0;
    }
    rep(i, 4) {
      int dr[] = {0, 1, 0, -1};
      int dc[] = {1, 0, -1, 0};
      push(r + dr[i], c + dc[i], warp);
    }
    rep(dr, -2, 3) rep(dc, -2, 3) push(r + dr, c + dc, warp + 1);
  }
  wt(-1);
}
