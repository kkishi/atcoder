#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector<pair<int, int>> job(n);
  rep(i, n) cin >> job[i].first >> job[i].second;
  sort(job);

  int i = 0;
  priority_queue<int> que;
  int ans = 0;
  rep(j, m) {
    while (i < n && job[i].first <= j + 1) {
      que.push(job[i].second);
      ++i;
    }
    if (que.empty()) continue;
    ans += que.top();
    que.pop();
  }
  wt(ans);
}
