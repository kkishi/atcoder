#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  rep(i, n) if (p[i] != -1)-- p[i];

  vector parent(30, vector(n, int(0)));
  parent[0] = p;
  rep(i, 29) rep(j, n) {
    int x = parent[i][j];
    if (x != -1) x = parent[i][x];
    parent[i + 1][j] = x;
  }

  V<int> depth(n);
  rep(i, n) {
    int j = i;
    rrep(k, 30) if (int x = parent[k][j]; x != -1) {
      depth[i] += 1 << k;
      j = x;
    }
  }

  ints(q);
  rep(q) {
    ints(a, b);
    --a, --b;
    auto check = [&] {
      int d = depth[a] - depth[b];
      if (d <= 0) return false;
      rrep(i, 30) if ((d >> i) & 1) a = parent[i][a];
      return a == b;
    };
    wt(check());
  }
}
