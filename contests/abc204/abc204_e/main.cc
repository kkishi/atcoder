#include <bits/stdc++.h>

#include "atcoder.h"
// #include "binary_search.h"
#include "int_sqrt.h"

void Main() {
  ints(n, m);
  VV<tuple<int, int, int>> g(n);
  rep(m) {
    ints(a, b, c, d);
    --a, --b;
    g[a].eb(b, c, d);
    g[b].eb(a, c, d);
  }

  V<int> dist(n, big);
  low_priority_queue<tuple<int, int>> que;

  auto push = [&dist, &que](int u, int c) {
    if (dist[u] <= c) return;
    dist[u] = c;
    que.push({c, u});
  };

  push(0, 0);

  while (!que.empty()) {
    auto [c, u] = que.top();
    que.pop();
    if (c > dist[u]) continue;
    dbg(c, u);
    for (auto [v, C, D] : g[u]) {
      dbg(v, C, D);
      dbg(D, IntSqrt(D));
      int y = IntSqrt(D) - (c + 1);
      dbg(y);
      if (y < 0) y = 0;
      dbg(y);
      // dbg(y, c + y + D / (1 + c + y));
      auto f = [&](int x) { return c + x + C + D / (1 + c + x); };
      if (y > 0 && (f(y) > f(y - 1))) --y;
      if (f(y) > f(y + 1)) ++y;
      push(v, f(y));
      dbg(y);
      rep(i, 10) dbg(i, f(i));
#ifdef DEBUG
      int min_v = big, min_i;
      rep(i, 100) {
        if (chmin(min_v, f(i))) {
          min_i = i;
        }
      }
      dbg(min_v, min_i);
      assert(min_v == f(y));
#endif
      /*
      for (int i = -1; i <= 1; ++i) {
        int Y = y + i;
        if (Y < 0) continue;
        push(v, c + Y + C + D / (1 + c + Y));
      }
      */

      /*
      int x = BinarySearch<int>(c, big, [&](int x) {
        int A = x + D / (1 + x);
        ++x;
        int B = x + D / (1 + x);
        return A >= B;
      });
      */
      /*
      for (int i = -1; i <= 1; ++i) {
        int X = x + i;
        if (X < c) continue;

        push(v, X + C + D / (1 + X));
      }
      */
      /*
      int A = x + d / (1 + x);
      int X = x + 1;
      int B = X + d / (1 + X);
      dbg(x, A, B);
      push(v, x + c + d / (1 + x));
      */
    }
  }
  int ans = dist[n - 1];
  if (ans == big) ans = -1;
  wt(ans);
}
