#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l);
  V<int> a(n);
  cin >> a;
  int tot = accumulate(a);
  low_priority_queue<int> que;
  each(e, a) que.push(e);
  if (l > tot) {
    que.push(l - tot);
  }
  int ans = 0;
  while (sz(que) > 1) {
    int x = que.top();
    que.pop();
    int y = que.top();
    que.pop();
    ans += x + y;
    que.push(x + y);
  }
  wt(ans);
}
