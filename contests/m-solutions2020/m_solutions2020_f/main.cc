#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  vector<ll> x(n), y(n);
  vector<char> u(n);
  rep(i, n) cin >> x[i] >> y[i] >> u[i];

  const ll M = 400001;
  const ll inf = numeric_limits<ll>::max();
  ll t = inf;
  rep(rot, 4) {
    // R L
    {
      vector<vector<ll>> r(M);
      rep(i, n) if (u[i] == 'R') r[y[i]].push_back(x[i]);
      rep(i, M) sort(all(r[i]));
      rep(i, n) if (u[i] == 'L') {
        const auto& ri = r[y[i]];
        if (ri.empty()) continue;
        auto it = lower_bound(all(ri), x[i]);
        if (it != ri.begin()) {
          if (ll d = x[i] - *(it - 1); d > 0) {
            chmin(t, d * 10 / 2);
          }
        }
      }
    }
    // R U
    {
      vector<vector<ll>> r(M);
      rep(i, n) if (u[i] == 'R') r[x[i] + y[i]].push_back(x[i]);
      rep(i, M) sort(all(r[i]));
      rep(i, n) if (u[i] == 'U') {
        const auto& ri = r[x[i] + y[i]];
        if (ri.empty()) continue;
        auto it = lower_bound(all(ri), x[i]);
        if (it != ri.begin()) {
          if (ll d = x[i] - *(it - 1); d > 0) {
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
  if (t == inf) {
    wt("SAFE");
  } else {
    wt(t);
  }
}
