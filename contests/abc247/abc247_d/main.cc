#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(q);
  deque<pair<int, int>> que;
  rep(q) {
    ints(k);
    if (k == 1) {
      ints(x, c);
      que.emplace_back(x, c);
    } else {
      ints(c);
      int ans = 0;
      while (c > 0) {
        auto& [X, C] = que.front();
        int y = min(c, C);
        ans += X * y;
        c -= y;
        C -= y;
        if (C == 0) que.pop_front();
      }
      wt(ans);
    }
  }
}
