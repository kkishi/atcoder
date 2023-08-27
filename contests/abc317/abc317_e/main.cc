#include <bits/stdc++.h>

#include "atcoder.h"
#include "grid.h"

void Main() {
  ints(h, w);
  V<string> a(h);
  cin >> a;
  int sr, sc, gr, gc;
  rep(i, h) rep(j, w) {
    char A = a[i][j];
    if (A == 'S') sr = i, sc = j;
    if (A == 'G') gr = i, gc = j;
    const string person = ">v<^";
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    rep(d, 4) if (person[d] == A) {
      int r = i, c = j;
      while (true) {
        r += dr[d];
        c += dc[d];
        if (!inside(r, c, h, w)) break;
        char B = a[r][c];
        if (B == '#' || person.find(B) != string::npos) break;
        a[r][c] = '!';
      }
    }
  }
  Grid<int> g(h, w);
  rep(i, h) rep(j, w) {
    switch (a[i][j]) {
      case '.':
      case 'S':
      case 'G':
        g.Set(i, j, 1);
    }
  }
  auto ans = g.Distance(sr, sc)[gr][gc];
  if (!ans) {
    wt(-1);
  } else {
    wt(*ans);
  }
}
