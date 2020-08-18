#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, m);
  vector<ll> x(m);
  cin >> x;

  sort(all(x));
  ll ans = x[m - 1] - x[0];

  vector<ll> d(m - 1);
  rep(i, m - 1) d[i] = x[i + 1] - x[i];
  sort(all(d), greater());

  rep(i, min<ll>(n - 1, d.size())) ans -= d[i];
  wt(ans);
}
