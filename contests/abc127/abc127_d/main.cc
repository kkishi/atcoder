#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, m);
  map<ll, ll> as;
  rep(i, n) {
    rd(ll, a);
    ++as[a];
  }
  rep(i, m) {
    rd(ll, b, c);
    ll changed = 0;
    while (changed < n && b > 0) {
      auto [k, v] = *as.begin();
      if (k >= c) {
        break;
      }
      ll change = min(b, v);
      if (change == v) {
        as.erase(as.begin());
      } else {
        as[k] -= change;
      }
      changed += change;
      b -= change;
    }
    as[c] += changed;
  }
  ll ans = 0;
  for (auto [k, v] : as) ans += k * v;
  wt(ans);
}
