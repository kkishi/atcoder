#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

void Main() {
  ints(n, m);
  int inf = numeric_limits<int>::max() / 10;
  vector dist(n, vector(n, inf));
  rep(i, n) dist[i][i] = 0;
  rep(m) {
    ints(a, b, c);
    --a, --b;
    dist[a][b] = dist[b][a] = c;
  }
  WarshallFloyd(dist);

  int sum = 0;
  rep(i, n) rep(j, n) sum += dist[i][j];

  ints(k);
  rep(k) {
    ints(x, y, z);
    --x, --y;
    rep(2) {
      int& dxy = dist[x][y];
      chmin(z, dxy);
      sum -= dxy - z;
      dxy = z;
      swap(x, y);
    }
    rep(i, n) rep(j, n) {
      rep(2) {
        int d = dist[i][x] + dist[x][y] + dist[y][j];
        int& dij = dist[i][j];
        if (dij > d) {
          sum -= dij - d;
          dij = d;
        }
        swap(x, y);
      }
    }
    wt(sum / 2);
  }
}
