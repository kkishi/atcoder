#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d);
  V<pair<int, int>> v(n);
  cin >> v;
  sort(v);
  int ans = 0;
  low_priority_queue<int> que;
  each(l, r, v) {
    if (!que.empty() && que.top() < l) {
      ++ans;
      que = {};
    }
    que.push(r + d - 1);
  }
  if (!que.empty()) ++ans;
  wt(ans);
}
