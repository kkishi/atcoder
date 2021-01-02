#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(H, W, K);
  V<string> s(H);
  cin >> s;

  VV<int> tot(H + 1, V<int>(W + 1));
  rep(i, H) rep(j, W) {
    tot[i + 1][j + 1] =
        tot[i][j + 1] + tot[i + 1][j] - tot[i][j] + (s[i][j] == '1');
  }

  vector<int> assignments;
  wt(Fix([&](auto dfs, int h) -> int {
    const int INF = 10 * 1000 * 1000;
    if (h == H) {
      int prev = -1;
      int cuts = 0;
      rep(w, W) {
        bool need_cut = false;
        rep(ai, assignments.size()) {
          auto cnt = [&](int hh, int hw, int lh, int lw) {
            return tot[hh][hw] - tot[lh][hw] - tot[hh][lw] + tot[lh][lw];
          };
          int lh = (ai == 0 ? 0 : assignments[ai - 1]);
          int hh = assignments[ai];
          int before = cnt(hh, w, lh, prev);
          int after = cnt(hh, w + 1, lh, prev);
          if (after - before > K) return INF;
          if (after > K) need_cut = true;
        }
        if (need_cut) {
          ++cuts;
          prev = w;
        }
      }
      return cuts + assignments.size() - 1;
    }
    int ans = INF;
    for (++h; h <= H; ++h) {
      assignments.pb(h);
      chmin(ans, dfs(h));
      assignments.pop_back();
    }
    return ans;
  })(0));
}
