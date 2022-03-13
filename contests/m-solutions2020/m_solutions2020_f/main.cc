#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> x(n), y(n);
  vector<char> u(n);
  rep(i, n) cin >> x[i] >> y[i] >> u[i];

  const int M = 400001;
  int t = big;
  rep(rot, 4) {
    // R L
    {
      vector<vector<int>> r(M);
      rep(i, n) if (u[i] == 'R') r[y[i]].pb(x[i]);
      rep(i, M) sort(r[i]);
      rep(i, n) if (u[i] == 'L') {
        const auto& ri = r[y[i]];
        if (ri.empty()) continue;
        auto it = lower_bound(all(ri), x[i]);
        if (it != ri.begin()) {
          if (int d = x[i] - *(it - 1); d > 0) {
            chmin(t, d * 10 / 2);
          }
        }
      }
    }
    // R U
    {
      vector<vector<int>> r(M);
      rep(i, n) if (u[i] == 'R') r[x[i] + y[i]].pb(x[i]);
      rep(i, M) sort(r[i]);
      rep(i, n) if (u[i] == 'U') {
        const auto& ri = r[x[i] + y[i]];
        if (ri.empty()) continue;
        auto it = lower_bound(all(ri), x[i]);
        if (it != ri.begin()) {
          if (int d = x[i] - *(it - 1); d > 0) {
            chmin(t, d * 10);
          }
        }
      }
    }
    // Rotate 90 degrees.
    rep(i, n) {
      int nx = 200000 - y[i];
      int ny = x[i];
      x[i] = nx;
      y[i] = ny;
      u[i] =
          map<char, char>{{'R', 'U'}, {'L', 'D'}, {'U', 'L'}, {'D', 'R'}}[u[i]];
    }
  }
  if (t == big) {
    wt("SAFE");
  } else {
    wt(t);
  }
}
