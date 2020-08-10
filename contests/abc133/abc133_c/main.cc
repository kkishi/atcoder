#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ll ans = numeric_limits<ll>::max();
  rd(ll, l, r);
  for (ll i = l; i < r; ++i) {
    for (ll j = i + 1; j <= r; ++j) {
      ll k = i * j % 2019;
      if (k == 0) {
        wt(0);
        return 0;
      }
      ans = min(ans, k);
    }
  }
  wt(ans);
}
