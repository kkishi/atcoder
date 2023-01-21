#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
  return {a.first + b.first, a.second + b.second};
}

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<string> s(n);
  cin >> s;
  vector dist(n, vector(n, pair<int, int>(big, 0)));
  rep(i, n) rep(j, n) if (s[i][j] == 'Y') dist[i][j] = {1, -a[j]};
  WarshallFloyd(dist);
  ints(q);
  rep(q) {
    ints(u, v);
    --u, --v;
    auto [d, c] = dist[u][v];
    if (d == big) {
      wt("Impossible");
    } else {
      wt(d, a[u] - c);
    }
  }
}
