#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, k);
  vector<ll> x(n);
  rep(i, n) cin >> x[i];
  ll ans = numeric_limits<ll>::max();
  for (int i = k - 1; i < n; ++i) {
    ll l = x[i - (k - 1)], h = x[i];
    ans = min(ans, h - l + min(abs(h), abs(l)));
  }
  wt(ans);
}
