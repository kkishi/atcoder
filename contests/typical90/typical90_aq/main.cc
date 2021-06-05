#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector dp(h, vector(w, vector(4, big)));
  ints(rs, cs);
  --rs, --cs;
  ints(rt, ct);
  --rt, --ct;
  V<string> s(h);
  cin >> s;
  deque<tuple<int, int, int, int>> que;
  rep(i, 4) {
    dp[rs][cs][i] = 0;
    que.emplace_back(rs, cs, i, 0);
  }
  while (!que.empty()) {
    auto [r, c, d, di] = que.front();
    que.pop_front();
    auto n = adjacent(r, c);
    rep(nd, 4) {
      auto [nr, nc] = n[nd];
      if (inside(nr, nc, h, w) && s[nr][nc] == '.') {
        int ndi = di + (d != nd);
        if (chmin(dp[nr][nc][nd], ndi)) {
          if (ndi == di) {
            que.emplace_front(nr, nc, nd, ndi);
          } else {
            que.emplace_back(nr, nc, nd, ndi);
          }
        }
      }
    }
  }
  int ans = big;
  rep(i, 4) chmin(ans, dp[rt][ct][i]);
  wt(ans);
}
