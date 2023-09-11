#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  vector c(3, vector(3, int(0)));
  cin >> c;
  vector seen(3, vector(3, false));
  int all_cnt = 0;
  int ok_cnt = 0;
  Fix([&](auto rec, int depth, const bool ok) {
    if (depth == 9) {
      ++all_cnt;
      if (ok) ++ok_cnt;
      return;
    }
    rep(i, 3) rep(j, 3) if (!seen[i][j]) {
      seen[i][j] = true;
      bool nok = ok;
      // vertical
      {
        V<int> v;
        rep(k, 3) if (k != i && seen[k][j]) v.pb(c[k][j]);
        if (sz(v) == 2 && v[0] == v[1]) nok = false;
      }
      // horizontal
      {
        V<int> v;
        rep(k, 3) if (k != j && seen[i][k]) v.pb(c[i][k]);
        if (sz(v) == 2 && v[0] == v[1]) nok = false;
      }
      // diagonal
      if (i == j) {
        V<int> v;
        rep(k, 3) if (k != i && seen[k][k]) v.pb(c[k][k]);
        if (sz(v) == 2 && v[0] == v[1]) nok = false;
      }
      // diagonal
      if (i == 2 - j) {
        V<int> v;
        rep(k, 3) if (k != i && seen[k][2 - k]) v.pb(c[k][2 - k]);
        if (sz(v) == 2 && v[0] == v[1]) nok = false;
      }
      rec(depth + 1, nok);
      seen[i][j] = false;
    }
  })(0, true);
  wt(double(ok_cnt) / all_cnt);
}
