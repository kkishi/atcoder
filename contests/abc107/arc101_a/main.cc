#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, k);
  vector<ll> x(n);
  cin >> x;
  ll ans = numeric_limits<ll>::max();
  rep(i, k - 1, n) {
    ll l = x[i - (k - 1)], h = x[i];
    chmin(ans, h - l + min(abs(h), abs(l)));
  }
  wt(ans);
}
