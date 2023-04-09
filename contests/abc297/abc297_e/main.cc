#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  low_priority_queue<int> que;
  que.push(0);
  set<int> seen;
  int cnt = 0;
  while (true) {
    auto val = que.top();
    que.pop();
    if (++cnt == k + 1) {
      wt(val);
      return;
    }
    rep(i, n) {
      int nval = val + a[i];
      if (seen.count(nval)) continue;
      seen.insert(nval);
      que.push(nval);
    }
  }
}
