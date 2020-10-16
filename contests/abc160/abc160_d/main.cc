#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, X, Y);
  --X, --Y;

  V<int> dist(N);
  rep(j, 1, N) rep(i, j) {
    ++dist[min(
        {j - i, abs(X - i) + 1 + abs(Y - j), abs(Y - i) + 1 + abs(X - j)})];
  }
  rep(i, 1, N) wt(dist[i]);
}
