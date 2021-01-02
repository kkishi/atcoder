#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, w, c);
  V<int> l(n), r(n), p(n);
  rep(i, n) cin >> l[i] >> r[i] >> p[i];

  V<int> idx(n);
  iota(all(idx), 0);
  sort(all(idx), [&l](int a, int b) { return l[a] < l[b]; });

  set<int> s(all(r));
  s.insert(0);
  low_priority_queue<pair<int, int>> que;
  int ans = big;
  int cost = 0;
  auto it = idx.begin();
  for (int L : s) {
    int R = L + c;
    if (R > w) continue;
    while (it != idx.end() && l[*it] < R) {
      que.push({r[*it], p[*it]});
      cost += p[*it];
      ++it;
    }
    while (!que.empty() && que.top().first <= L) {
      cost -= que.top().second;
      que.pop();
    }
    chmin(ans, cost);
  }
  wt(ans);
}
