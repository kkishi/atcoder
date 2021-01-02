#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> transportation(5);
  cin >> transportation;
  vector<int> population(6);
  population[0] = n;
  int ans = 0;
  int last_change = 0;
  while (population[5] < n) {
    ++ans;
    vector<int> change(6);
    rep(i, 5) {
      int c = min(transportation[i], population[i]);
      change[i] -= c;
      change[i + 1] += c;
    }
    rep(i, 6) population[i] += change[i];
    if (last_change > 0 && change[5] == last_change) {
      wt(ans + div_ceil(n - population[5], last_change));
      return;
    }
    last_change = change[5];
  }
  wt(ans);
}
