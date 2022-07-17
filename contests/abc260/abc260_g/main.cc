#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> s(n);
  cin >> s;
  /*
    8 2
    OXXXXXXX
    XXXXXXXX
    XXXXXXXX
   */
  vector g(n, vector(n, int(0)));
  auto ch = [&](int i, int j, int d) {
    if (inside(i, j, n, n)) g[i][j] += d;
  };
  rep(i, n) rep(j, n) if (s[i][j] == 'O') {
    int I = i + m;
    int J = j;
    if (I > n - 1) {
      J += 2 * (I - (n - 1));
      I = n - 1;
    }
    ch(I, J, -1);
    ch(i, j + m * 2, +1);
    ch(I, J + 2, +1);
    ch(i, j + m * 2 + 2, -1);

    /*
      OXXX+X-X
      XXXXXXXX
      -X+XXXXX
     */
  }
  rrep(i, n) rep(j, n) ch(i - 1, j + 2, g[i][j]);
  /*
    OXXXXXXX
    XX-X+XXX
    -X+XXXXX
   */
  rep(i, n) rep(j, n) if (s[i][j] == 'O') {
    ch(i, j, 1);
    ch(i, j + m * 2, -1);
    /*
      +XXX-XXX
      XX-X+XXX
      -X+XXXXX
     */
  }
  rep(i, n) rep(j, n) ch(i, j + 1, g[i][j]);
  /*
    ++++XXXX
    XX--XXXX
    --XXXXXX
   */
  rep(j, n) rep(i, n) ch(i + 1, j, g[i][j]);
  /*
    ++++XXXX
    ++XXXXXX
    XXXXXXXX
   */
  ints(q);
  rep(q) {
    ints(x, y);
    wt(g[x - 1][y - 1]);
  }
}
