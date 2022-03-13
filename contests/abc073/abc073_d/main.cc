#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

void Main() {
  ints(n, m, R);
  V<int> r(R);
  cin >> r;
  VV<int> dist(n, V<int>(n, big));
  rep(m) {
    ints(a, b, c);
    --a, --b;
    dist[a][b] = dist[b][a] = c;
  }
  WarshallFloyd(dist);
  sort(r);
  int ans = big;
  do {
    int sum = 0;
    rep(i, R - 1) sum += dist[r[i] - 1][r[i + 1] - 1];
    chmin(ans, sum);
  } while (next_permutation(all(r)));
  wt(ans);
}
