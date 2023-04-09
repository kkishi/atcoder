#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  low_priority_queue<int> que;
  que.push(0);
  int cnt = 0;
  int prev = -1;
  while (true) {
    auto val = que.top();
    que.pop();
    if (val == prev) continue;
    prev = val;
    if (++cnt == k + 1) {
      wt(val);
      return;
    }
    rep(i, n) que.push(val + a[i]);
  }
}
