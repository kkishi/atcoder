#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(r, c);
  vector g(n, string(n, '.'));
  vector col(n, vector(3, false));
  Fix([&](auto rec, int depth) -> void {
    if (depth == n) {
      bool ok = true;
      rep(i, n) rep(j, n) if (g[i][j] != '.') {
        if (g[i][j] != r[i]) ok = false;
        break;
      }
      rep(i, n) rep(j, n) if (g[j][i] != '.') {
        if (g[j][i] != c[i]) ok = false;
        break;
      }
      if (ok) {
        wt("Yes");
        each(e, g) wt(e);
        exit(0);
      }
    } else {
      rep(i, n) rep(j, n) rep(k, n) {
        if (i == j || i == k | j == k) continue;
        if (col[i][0] || col[j][1] || col[k][2]) continue;

        col[i][0] = col[j][1] = col[k][2] = true;
        g[depth][i] = 'A';
        g[depth][j] = 'B';
        g[depth][k] = 'C';

        rec(depth + 1);

        col[i][0] = col[j][1] = col[k][2] = false;
        g[depth][i] = '.';
        g[depth][j] = '.';
        g[depth][k] = '.';
      }
    }
  })(0);
  wt("No");
}
