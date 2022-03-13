#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y, z, k);
  vector<int> a(x), b(y), c(z);
  cin >> a >> b >> c;
  sort(a, greater{});
  sort(b, greater{});
  sort(c, greater{});
  set<tuple<int, int, int>> seen;
  priority_queue<pair<int, tuple<int, int, int>>> que;
  auto push = [&](int ai, int bi, int ci) {
    if (ai == a.size() || bi == b.size() || ci == c.size()) {
      return;
    }
    tuple<int, int, int> t = {ai, bi, ci};
    if (!seen.insert(t).second) return;
    que.push({a[ai] + b[bi] + c[ci], t});
  };
  push(0, 0, 0);
  rep(i, k) {
    auto [s, t] = que.top();
    que.pop();
    wt(s);
    auto [ai, bi, ci] = t;
    push(ai + 1, bi, ci);
    push(ai, bi + 1, ci);
    push(ai, bi, ci + 1);
  }
}
