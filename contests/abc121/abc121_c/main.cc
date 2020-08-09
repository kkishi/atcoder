#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, m);
  vector<pair<ll, ll>> ab(n);
  rep(i, n) cin >> ab[i].first >> ab[i].second;
  sort(all(ab));
  ll ans = 0;
  for (int i = 0; m > 0; ++i) {
    ll dm = min(m, ab[i].second);
    ans += ab[i].first * dm;
    m -= dm;
  }
  wt(ans);
}
