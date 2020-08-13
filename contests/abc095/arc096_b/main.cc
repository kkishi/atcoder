#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, c);
  V<ll> x(n), v(n);
  rep(i, n) cin >> x[i] >> v[i];
  auto f = [&n](const V<ll>& x, const V<ll>& v) {
    V<ll> y(n + 1);
    ll p = 0;
    ll c = 0;
    rep(i, n) {
      c = c + v[i] - (x[i] - p);
      p = x[i];
      y[i + 1] = max(y[i], c);
    }
    return y;
  };
  V<ll> rx = x;
  reverse(all(rx));
  rep(i, n) rx[i] = c - rx[i];
  V<ll> rv = v;
  reverse(all(rv));

  V<ll> l = f(x, v);
  V<ll> r = f(rx, rv);

  ll ans = max(l[n], r[n]);
  for (int i = 1; i < n; ++i) {
    ans = max(ans, l[i] - x[i - 1] + r[n - i]);
    ans = max(ans, r[i] - rx[i - 1] + l[n - i]);
  }
  wt(ans);
}
