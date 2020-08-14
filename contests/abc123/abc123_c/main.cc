#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  vector<ll> transportation(5);
  cin >> transportation;
  vector<ll> population(6);
  population[0] = n;
  ll ans = 0;
  while (population[5] < n) {
    ++ans;
    vector<ll> change(6);
    rep(i, 5) {
      ll c = min(transportation[i], population[i]);
      change[i] -= c;
      change[i + 1] += c;
    }
    rep(i, 6) population[i] += change[i];
    rep(i, 6) cerr << change[i] << " ";
    cerr << endl;
    if (population[0] > 0) {
      bool fixed = true;
      // 0 a 1 b 2 c 3 d 4 e 5
      rep(i, 4) if (change[i + 1] != 0) fixed = false;
      if (fixed) {
        ll repeat = population[0] / -change[0];
        ans += repeat;
        population[0] += change[0] * repeat;
        population[5] += change[5] * repeat;
      }
    }
  }
  wt(ans);
}
