#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector<int> v(n);
  cin >> v;
  int ans = 0;
  for (int l = 0; l <= min(k, n); ++l) {
    for (int r = 0; r + l <= min(k, n); ++r) {
      low_priority_queue<int> q;
      rep(i, l) q.push(v[i]);
      rep(i, r) q.push(v[n - 1 - i]);
      rep(i, k - (l + r)) {
        if (!q.empty() && q.top() < 0) q.pop();
      }
      int sum = 0;
      while (!q.empty()) {
        sum += q.top();
        q.pop();
      }
      chmax(ans, sum);
    }
  }
  wt(ans);
}
