#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  int ans = 0;
  queue<int> que;
  auto idx = [&n](int i) { return (i + n) % n; };
  auto adj = [&](int i) { return b[idx(i - 1)] + b[idx(i + 1)]; };
  auto ok = [&](int i) { return b[i] >= max(a[i], adj(i)); };
  rep(i, n) if (ok(i)) que.push(i);
  while (!que.empty()) {
    int i = que.front();
    que.pop();
    int x = adj(i);
    int y = (b[i] - a[i]) / x;
    ans += y;
    b[i] -= y * x;
    if (ok(idx(i - 1))) que.push(idx(i - 1));
    if (ok(idx(i + 1))) que.push(idx(i + 1));
  }
  rep(i, n) if (a[i] != b[i]) {
    wt(-1);
    return;
  }
  wt(ans);
}
