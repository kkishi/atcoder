#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(T);
  while (T--) {
    ints(N, A, B, C, D);

    map<int, int> seen;
    seen[N] = 0;

    low_priority_queue<pair<int, int>> que;
    que.push({0, N});

    while (!que.empty()) {
      auto [c, v] = que.top();
      que.pop();
      if (v == 0) {
        wt(c);
        break;
      }
      auto push = [&seen, &que](int c, int v) {
        if (v < 0) return;
        auto [it, ok] = seen.insert({v, c});
        if (ok || it->second > c) {
          it->second = c;
          que.push({c, v});
        }
      };
      if (v % 2 == 0) push(c + A, v / 2);
      if (v % 3 == 0) push(c + B, v / 3);
      if (v % 5 == 0) push(c + C, v / 5);
      for (int d = -4; d <= 4; ++d) {
        int nv = v + d;
        bool ok = false;
        int mods[] = {2, 3, 5};
        for (int m : mods) {
          if (v % m != 0 && nv % m == 0 && abs(d) < m) {
            ok = true;
          }
        }
        if (ok) push(c + D * abs(d), nv);
      }
      if (D * v > 0) {
        push(c + D * v, 0);
      }
    }
  }
}
