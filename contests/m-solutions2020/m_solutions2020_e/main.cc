#include <bits/stdc++.h>

#include "macros.h"
#include "setmin.h"

using namespace std;

int main() {
  rd(ll, n);
  vector<ll> x(n), y(n), p(n);
  rep(i, n) cin >> x[i] >> y[i] >> p[i];
  vector<ll> ans(n + 1, numeric_limits<ll>::max());
  function<void(int, int, vector<ll>)> rec = [&](int depth, int k,
                                                 vector<ll> dist) {
    if (depth == n) {
      ll S = 0;
      rep(i, n) S += p[i] * dist[i];
      Setmin(ans[k], S);
      return;
    }
    rec(depth + 1, k, dist);
    {
      // x
      vector<ll> ndist = dist;
      rep(i, n) Setmin(ndist[i], abs(x[i] - x[depth]));
      rec(depth + 1, k + 1, ndist);
    }
    {
      // y
      vector<ll> ndist = dist;
      rep(i, n) Setmin(ndist[i], abs(y[i] - y[depth]));
      rec(depth + 1, k + 1, ndist);
    }
  };
  vector<ll> dist(n);
  rep(i, n) dist[i] = min(abs(x[i]), abs(y[i]));
  rec(0, 0, dist);
  for (int k = 0; k <= n; ++k) {
    wt(ans[k]);
  }
}
