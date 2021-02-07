#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, r, c);
  V<string> s(h);
  cin >> s;
  vector visited(h, vector(w, false));
  visited[r - 1][c - 1] = true;
  queue<pair<int, int>> que;
  que.emplace(r - 1, c - 1);
  while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop();
    rep(i, 4) {
      int dr[] = {0, 1, 0, -1};
      int dc[] = {1, 0, -1, 0};
      int pr = r + dr[i];
      int pc = c + dc[i];
      if (0 <= pr && pr < h && 0 <= pc && pc < w & !visited[pr][pc]) {
        char x = s[pr][pc];
        if (x == '#') continue;
        if (x == '<' && i != 0) continue;
        if (x == '^' && i != 1) continue;
        if (x == '>' && i != 2) continue;
        if (x == 'v' && i != 3) continue;
        visited[pr][pc] = true;
        que.emplace(pr, pc);
      }
    }
  }
  rep(i, h) {
    rep(j, w) cout << (s[i][j] == '#' ? '#' : visited[i][j] ? 'o' : 'x');
    cout << endl;
  }
}
