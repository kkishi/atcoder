#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, m);
  vector<ll> x(m);
  rep(i, m) cin >> x[i];

  sort(all(x));
  ll ans = x[m - 1] - x[0];

  vector<ll> d(m - 1);
  rep(i, m - 1) d[i] = x[i + 1] - x[i];
  sort(all(d), greater());

  for (ll i = 0; i < min<ll>(n - 1, d.size()); ++i) ans -= d[i];
  wt(ans);
}
