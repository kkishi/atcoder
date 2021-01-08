#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(int, h, w);
  vector a(h, vector(w, 0));
  rep(i, h) rep(j, w) cin >> a[i][j];
  vector prev_r(h, vector(w, -1));
  vector prev_c(h, vector(w, -1));
  vector visited(h, vector(w, false));
  vector<string> moves;
  rep(i, h) rep(j, w) if (!visited[i][j] && (a[i][j] & 1)) {
    queue<tuple<int, int>> q;
    q.push({i, j});
    vector seen(h, vector(w, false));
    dbg(i, j);
    bool found = false;
    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      seen[r][c] = true;
      if ((r != i || c != j) && (a[r][c] & 1)) {
        dbg(r, c);
        while (r != i || c != j) {
          visited[r][c] = true;
          int pr = prev_r[r][c];
          int pc = prev_c[r][c];
          stringstream ss;
          ss << (r + 1) << " " << (c + 1) << " " << (pr + 1) << " " << (pc + 1);
          moves.pb(ss.str());
          r = pr;
          c = pc;
        }
        visited[r][c] = true;
        found = true;
        break;
      }
      int dr[] = {1, -1, 0, 0};
      int dc[] = {0, 0, 1, -1};
      rep(i, 4) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        dbg(nr, nc);
        if (nr < 0 || h <= nr || nc < 0 || w <= nc || seen[nr][nc]) {
          continue;
        }
        prev_r[nr][nc] = r;
        prev_c[nr][nc] = c;
        q.push({nr, nc});
      }
    }
    if (!found) break;
  }
  wt(moves.size());
  for (const string& m : moves) wt(m);
}
