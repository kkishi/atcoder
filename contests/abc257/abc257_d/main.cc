#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "disjoint_set.h"
#include "i128.h"

void Main() {
  ints(n);
  V<int> x(n), y(n), p(n);
  rep(i, n) cin >> x[i] >> y[i] >> p[i];
  wt(BinarySearch<int>(int(10000000000LL), 0, [&](int s) {
    rep(i, n) {
      queue<int> que;
      que.push(i);
      V<int> seen(n);
      seen[i] = true;
      int cnt = 1;
      while (!que.empty()) {
        int i = que.front();
        que.pop();
        rep(j, n) {
          if (seen[j]) continue;
          int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
          if (i128(p[i]) * i128(s) >= i128(d)) {
            seen[j] = true;
            ++cnt;
            que.push(j);
          }
        }
      }
      if (cnt == n) return true;
    }
    return false;
  }));
}
