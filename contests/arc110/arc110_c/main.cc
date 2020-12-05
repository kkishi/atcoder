#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  rep(i, n)-- p[i];

  V<bool> used(n - 1);
  queue<int> que;
  auto check = [&](int i) {
    if (p[i] > i && p[i + 1] < i + 1) que.push(i);
  };
  rep(i, n - 1) check(i);
  V<int> ans;
  while (!que.empty()) {
    int i = que.front();
    que.pop();
    if (used[i]) continue;
    used[i] = true;
    swap(p[i], p[i + 1]);
    ans.push_back(i);
    if (i > 0) check(i - 1);
    if (i + 2 < n) check(i + 1);
  }
  rep(i, n) if (p[i] != i) {
    wt(-1);
    return;
  }
  if (sz(ans) != n - 1) {
    wt(-1);
    return;
  }
  rep(i, sz(ans)) wt(ans[i] + 1);
}
