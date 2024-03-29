#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"
#include "max_flow.h"

void Main() {
  ints(h, w);
  V<string> c(h);
  cin >> c;
  MaxFlow mf;
#define cell(r, c) ((r)*w + c)
#define s cell(h, 0)
#define t (s + 1)
  int sum = 0;
  rep(i, h) rep(j, w) {
    char C = c[i][j];
    int idx = cell(i, j);
    if (C == '2' || C == '?') {
      int min_flow = C == '2' ? 1 : 0;
      sum += min_flow;
      if (even(i + j)) {
        mf.Add(s, idx, 1, min_flow);
      } else {
        mf.Add(idx, t, 1, min_flow);
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
              mf.Add(idx, nidx, 1);
            } else {
              mf.Add(nidx, idx, 1);
            }
          }
        }
      }
    }
  }
  wt(mf.Flow(s, t) != -1);
}
