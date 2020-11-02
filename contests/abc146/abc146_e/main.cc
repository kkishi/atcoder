#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector<int> a(n);
  cin >> a;
  map<int, int> seen;
  queue<int> que;
  auto add = [&](int x) {
    seen[x]++;
    que.push(x);
    if (que.size() == k) {
      int y = que.front();
      dbg(x, y);
      que.pop();
      seen[y]--;
    }
  };
  add(0);
  int sum = 0;
  int ans = 0;
  rep(i, n) {
    sum += a[i];
    int adj = (sum - (i + 1)) % k;
    ans += seen[adj];
    add(adj);
  }
  wt(ans);
}
