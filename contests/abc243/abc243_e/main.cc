#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

using P = pair<int, int>;
P operator+(const P& p, const P& q) {
  return {p.first + q.first, p.second + q.second};
}

void Main() {
  ints(n, m);
  vector g(n, vector(n, P{big, -big}));
  rep(i, n) g[i][i] = {0, 0};
  vector<tuple<int, int, int>> es;
  rep(m) {
    ints(a, b, c);
    --a, --b;
    es.eb(a, b, c);
    g[a][b] = {c, -1};
    g[b][a] = {c, -1};
  }
  WarshallFloyd(g);
  int ans = 0;
  for (auto [a, b, c] : es) {
    if (g[a][b] < P{c, -1}) {
      ++ans;
    }
  }
  wt(ans);
}
