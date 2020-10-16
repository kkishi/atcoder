#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<pair<int, int>> p(n), q(m);
  cin >> p >> q;
  for (auto&& pi : p) {
    int i, mini = numeric_limits<int>::max();
    rep(j, m) if (auto&& qj = q[j];
                  chmin(mini, abs(pi.first - qj.first) +
                                  abs(pi.second - qj.second))) {
      i = j;
    }
    wt(i + 1);
  }
}
