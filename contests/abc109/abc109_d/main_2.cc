#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(int, h, w);
  vector a(h, vector(w, 0));
  rep(i, h) rep(j, w) cin >> a[i][j];
  int r = 0, c = 0;
  vector<string> moves;
  while (true) {
    dbg(r, c);
    int nr = r, nc = c + ((r & 1) ? -1 : 1);
    if (nc < 0 || w <= nc) {
      ++nr;
      if (nr == h) break;
      nc = c;
    }
    if (a[r][c] & 1) {
      stringstream ss;
      ss << (r + 1) << " " << (c + 1) << " " << (nr + 1) << " " << (nc + 1);
      moves.push_back(ss.str());
      --a[r][c];
      ++a[nr][nc];
    }
    r = nr;
    c = nc;
  }
  wt(moves.size());
  for (auto& m : moves) wt(m);
}
