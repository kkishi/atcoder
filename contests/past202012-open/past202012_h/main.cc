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
    each(pr, pc, adjacent(r, c)) {
      if (inside(pr, pc, h, w) && !visited[pr][pc]) {
        char x = s[pr][pc];
        if (x == '#') continue;
        if (x == '<' && pc <= c) continue;
        if (x == '^' && pr <= r) continue;
        if (x == '>' && pc >= c) continue;
        if (x == 'v' && pr >= r) continue;
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
