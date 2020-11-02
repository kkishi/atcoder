#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(3 * n);
  cin >> a;
  V<int> left(3 * n);
  {
    low_priority_queue<int> que;
    int sum = 0;
    rep(i, 3 * n) {
      sum += a[i];
      que.push(a[i]);
      if (que.size() == n + 1) {
        sum -= que.top();
        que.pop();
      }
      if (que.size() == n) left[i] = sum;
    }
  }
  V<int> right(3 * n);
  {
    priority_queue<int> que;
    int sum = 0;
    rrep(i, 3 * n) {
      sum += a[i];
      que.push(a[i]);
      if (que.size() == n + 1) {
        sum -= que.top();
        que.pop();
      }
      if (que.size() == n) right[i] = sum;
    }
  }
  int ans = numeric_limits<int>::min();
  rep(i, n - 1, 2 * n) chmax(ans, left[i] - right[i + 1]);
  wt(ans);
}
