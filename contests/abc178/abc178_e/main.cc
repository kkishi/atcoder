#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  int ans = numeric_limits<int>::min();
  rep(2) {
    int maxi = numeric_limits<int>::min(), mini = numeric_limits<int>::max();
    rep(i, n) {
      chmax(maxi, x[i] + y[i]);
      chmin(mini, x[i] + y[i]);
    }
    chmax(ans, maxi - mini);

    rep(i, n) {
      int tmp = y[i];
      y[i] = x[i];
      x[i] = 1000000001 - tmp;
    }
  }
  wt(ans);
}
