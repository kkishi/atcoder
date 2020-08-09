#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, k);
  int n = 1 << k;

  vector<double> ratings(n);
  rep(i, n) cin >> ratings[i];

  map<pair<int, int>, double> memo;
  function<double(int, int)> prob = [&](int index, int wins) {
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
  };

  cout << fixed << setprecision(9);
  rep(i, n) wt(prob(i, k));
}
