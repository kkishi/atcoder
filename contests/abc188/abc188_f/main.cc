#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y);
  low_priority_queue<pair<int, int>> que;
  map<int, int> dist;
  auto push = [&](int d, int y) {
    auto [it, ok] = dist.insert({y, d});
    if (!ok && it->second <= d) return;
    it->second = d;
    que.push({d, y});
  };
  push(0, y);
  while (!que.empty()) {
    auto [d, y] = que.top();
    que.pop();
    if (x == y) {
      wt(d);
      break;
    }
    push(d + abs(x - y), x);
    if (x > y) continue;
    if (even(y)) {
      push(d + 1, y / 2);
    } else {
      push(d + 1, y + 1);
      push(d + 1, y - 1);
    }
  }
}
