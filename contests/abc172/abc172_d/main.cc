#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  vector<ll> p(n + 1);
  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = i; j <= n; j += i) {
      ++p[j];
    }
    ans += i * p[i];
  }
  wt(ans);
}
