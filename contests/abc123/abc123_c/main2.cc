#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  vector<ll> transportation(5);
  rep(i, 5) cin >> transportation[i];
  vector<ll> population(6);
  population[0] = n;
  ll ans = 0;
  ll last_change = 0;
  while (population[5] < n) {
    ++ans;
    vector<ll> change(6);
    rep(i, 5) {
      ll c = min(transportation[i], population[i]);
      change[i] -= c;
      change[i + 1] += c;
    }
    rep(i, 6) population[i] += change[i];
    if (last_change > 0 && change[5] == last_change) {
      wt(ans + (n - population[5] + last_change - 1) / last_change);
      return 0;
    }
    last_change = change[5];
  }
  wt(ans);
}
