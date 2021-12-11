#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  --a, --b;
  V<string> s(3);
  cin >> s;
  vector v(9, vector(9, false));
  v[a][b] = true;
  queue<pair<int, int>> que;
  que.emplace(a, b);
  while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop();
    rep(i, -1, 2) rep(j, -1, 2) {
      int nr = r + i;
      int nc = c + j;
      if (inside(nr, nc, 9, 9) && !v[nr][nc] && s[i + 1][j + 1] == '#') {
        v[nr][nc] = true;
        que.emplace(nr, nc);
      }
    }
  }
  int ans = 0;
  rep(i, 9) rep(j, 9) if (v[i][j])++ ans;
  wt(ans);
}
