#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  set<int> st;
  rep(i, n) st.insert(i);
  using E = tuple<int, int, int, int>;
  low_priority_queue<E> que;
  rep(m) {
    ints(t, w, s);
    que.emplace(t, 1, w, s);
  }
  V<int> ans(n);
  while (!que.empty()) {
    auto [t, kind, x, y] = que.top();
    que.pop();
    if (kind == 0) {
      st.insert(x);
    } else {
      if (st.empty()) continue;
      int i = *st.begin();
      st.erase(i);
      ans[i] += x;
      que.emplace(t + y, 0, i, -big);
    }
  }
  each(e, ans) wt(e);
}
