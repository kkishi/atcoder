#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph to(n);
  to.Read(m);
  V<int> colors(n, -1);
  stack<pair<int, int>> stk;
  stk.push({0, 0});
  bool ok = true;
  while (!stk.empty()) {
    auto [node, color] = stk.top();
    stk.pop();
    int& c = colors[node];
    if (c != -1) {
      if (c != color) ok = false;
      continue;
    }
    c = color;
    for (int child : to[node]) {
      stk.push({child, 1 - color});
    }
  }
  auto nC2 = [](int n) { return n * (n - 1) / 2; };
  int ans = nC2(n) - m;
  if (ok) {
    int cnt = 0;
    rep(i, n) if (colors[i] == 0)++ cnt;
    ans -= nC2(cnt) + nC2(n - cnt);
  }
  wt(ans);
}
