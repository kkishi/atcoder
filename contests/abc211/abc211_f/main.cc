#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

void Main() {
  ints(n);
  using P = pair<int, int>;
  V<tuple<int, int, int, int>> ts;
  const int ADD = 0, DEL = 1;
  rep(n) {
    ints(m);
    V<P> v(m);
    cin >> v;

    int minx = big;
    each(x, _, v) chmin(minx, x);
    int top_left = -1;
    rep(i, m) {
      auto [x, y] = v[i];
      if (x == minx) {
        if (top_left == -1 || v[top_left].second < y) {
          top_left = i;
        }
      }
    }
    int next = (top_left + 1) % m;
    bool clockwise = (v[next].second == v[top_left].second);

    rep(i, m) {
      auto [x0, y0] = v[i];
      auto [x1, y1] = v[(i + 1) % m];
      if (x0 == x1) {
        int op = (clockwise ^ (y0 > y1)) ? ADD : DEL;
        if (y0 > y1) swap(y0, y1);
        ts.eb(x0, op, y0, y1);
      }
    }
  }
  sort(ts);

  ints(q);
  V<tuple<int, int, int>> Q;
  rep(i, q) {
    ints(x, y);
    Q.eb(x, y, i);
  }
  sort(Q);

  DualSegmentTree<int> t(100001, [](int a, int b) { return a + b; });
  auto it = ts.begin();
  V<int> ans(q);
  for (auto [X, Y, i] : Q) {
    while (it != ts.end() && get<0>(*it) <= X) {
      auto [x, OP, y0, y1] = *it;
      ++it;
      t.Update(y0, y1, OP == ADD ? 1 : -1);
    }
    ans[i] = t.Get(Y);
  }
  each(e, ans) wt(e);
}
