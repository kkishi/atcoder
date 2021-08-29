#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> c(m);
  rep(i, m) {
    ints(k);
    rep(k) {
      ints(a);
      c[i].pb(a);
    }
    c[i].pb(big + i);
    reverse(all(c[i]));
  }
  using T = tuple<int, int>;
  queue<T> que;
  map<int, int> mp;
  auto pp = [&](int i) {
    int b = c[i].back();
    if (mp.count(b)) {
      que.push({i, mp[b]});
    } else {
      mp[b] = i;
    }
  };
  rep(i, m) pp(i);
  int taken = 0;
  while (!que.empty()) {
    auto [i, j] = que.front();
    que.pop();
    taken += 2;
    c[i].pop_back();
    pp(i);
    c[j].pop_back();
    pp(j);
  }
  wt(taken == 2 * n);
}
