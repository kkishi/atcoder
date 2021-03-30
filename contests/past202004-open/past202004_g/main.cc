#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  deque<pair<int, int>> que;
  ints(q);
  rep(q) {
    ints(t);
    if (t == 1) {
      rd(char, c);
      ints(x);
      que.emplace_back(c - 'a', x);
    } else {
      ints(d);
      map<int, int> del;
      while (d > 0 && !que.empty()) {
        auto [c, x] = que.front();
        que.pop_front();
        int y = min(x, d);
        del[c] += y;
        d -= y;
        if (y < x) {
          que.emplace_front(c, x - y);
        }
      }
      int ans = 0;
      each(_, v, del) ans += v * v;
      wt(ans);
    }
  }
}
