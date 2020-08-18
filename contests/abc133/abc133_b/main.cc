#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, d);
  vector<vector<int>> xs(n, vector(d, 0));
  rep(i, n) rep(j, d) cin >> xs[i][j];
  int ans = 0;
  rep(i, n - 1) for (int j = i + 1; j < n; ++j) {
    int sum = 0;
    auto sq = [](int x) { return x * x; };
    rep(k, d) sum += sq(xs[i][k] - xs[j][k]);
    for (int k = 0; k * k <= sum; ++k) {
      if (k * k == sum) ++ans;
    }
  }
  wt(ans);
}
