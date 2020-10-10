#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  int tot = 0;
  rep(i, h) rep(j, w) if (s[i][j] == '.')++ tot;

  vector l(h, vector(w, int(0)));
  rep(i, h) rep(j, w) if (s[i][j] == '.') l[i][j] = 1;
  vector r = l, u = l, d = l;
  rep(i, h) {
    rep(j, w - 1) l[i][j + 1] += (s[i][j] == '#' ? 0 : l[i][j]);
    rrep(j, w - 1) r[i][j] += (s[i][j + 1] == '#' ? 0 : r[i][j + 1]);
  }
  rep(i, w) {
    rep(j, h - 1) u[j + 1][i] += (s[j][i] == '#' ? 0 : u[j][i]);
    rrep(j, h - 1) d[j][i] += (s[j + 1][i] == '#' ? 0 : d[j + 1][i]);
  }

  mint ans = 0;
  rep(i, h) rep(j, w) if (s[i][j] == '.') {
    int x = l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3;
    dbg(l[i][j], r[i][j], u[i][j], d[i][j]);
    dbg(i, j, x);
    ans += mint(2).Pow(tot) - mint(2).Pow(tot - x);
  }
  wt(ans);
}
