#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  int n = 1 << k;

  vector<double> ratings(n);
  cin >> ratings;

  map<pair<int, int>, double> memo;

  cout << fixed << setprecision(9);
  rep(i, n) wt(Fix([&](auto prob, int index, int wins) -> double {
    pair<int, int> key = {index, wins};
    double& m = memo[key];
    if (m == 0) {
      if (wins == 0) {
        m = 1;
      } else {
        m = 0;
        int p = index;
        rep(i, wins - 1) p /= 2;
        p ^= 1;
        int l = p, r = p;
        rep(i, wins - 1) {
          l = l * 2;
          r = r * 2 + 1;
        }
        for (int i = l; i <= r; ++i) {
          if (i == index) continue;
          m += prob(i, wins - 1) /
               (1 + pow(10, (ratings[i] - ratings[index]) / 400));
        }
        m *= prob(index, wins - 1);
      }
    }
    return m;
  })(i, k));
}
