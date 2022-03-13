#include <bits/stdc++.h>

#include "atcoder.h"

struct Pair {
  int l, r;
  int Min() const { return min(l, r); }
  bool operator<(const Pair& p) const { return Min() < p.Min(); }
};

void Main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  sort(a, greater{});

  int ans = a[0];
  priority_queue<Pair> que;
  que.push({a[0], a[1]});
  que.push({a[1], a[0]});
  rep(i, 2, n) {
    Pair p = que.top();
    que.pop();
    ans += p.Min();
    que.push({p.l, a[i]});
    que.push({a[i], p.r});
  }
  wt(ans);
}
