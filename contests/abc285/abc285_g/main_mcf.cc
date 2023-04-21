// This solution is probably correct, but it's too slow.
#include <bits/stdc++.h>

#include "atcoder.h"
#include "min_cost_flow.h"

void Main() {
  ints(h, w);
  V<string> c(h);
  cin >> c;
  MinCostFlow mcf;
#define cell(r, c) ((r)*w + c)
#define s cell(h, 0)
#define t (s + 1)
  int sum = 0;
  rep(i, h) rep(j, w) {
    char C = c[i][j];
    int idx = cell(i, j);
    if (C == '2' || C == '?') {
      int cost = C == '2' ? -1000000 : 0;
      sum += cost;
      if (even(i + j)) {
        mcf.Add(s, idx, 1, cost);
      } else {
        mcf.Add(idx, t, 1, cost);
      }
      int di[] = {0, 1};
      int dj[] = {1, 0};
      rep(k, 2) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (inside(ni, nj, h, w)) {
          char D = c[ni][nj];
          int nidx = cell(ni, nj);
          if (D == '2' || D == '?') {
            if (even(i + j)) {
              mcf.Add(idx, nidx, 1, 0);
            } else {
              mcf.Add(nidx, idx, 1, 0);
            }
          }
        }
      }
    }
  }
  auto [_, cost] = mcf.Flow(s, t);
  wt(cost == sum);
}
