#include <bits/stdc++.h>

#include "macros.h"
#include "warshall_floyd.h"

using namespace std;

int main() {
  ints(n, m, R);
  V<int> r(R);
  cin >> r;
  int inf = numeric_limits<int>::max() / 10;
  VV<int> dist(n, V<int>(n, inf));
  rep(m) {
    ints(a, b, c);
    --a, --b;
    dist[a][b] = dist[b][a] = c;
  }
  WarshallFloyd(dist);
  sort(all(r));
  int ans = inf;
  do {
    int sum = 0;
    rep(i, R - 1) sum += dist[r[i] - 1][r[i + 1] - 1];
    chmin(ans, sum);
  } while (next_permutation(all(r)));
  wt(ans);
}
