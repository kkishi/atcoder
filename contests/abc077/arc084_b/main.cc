#include <bits/stdc++.h>

#include "atcoder.h"

auto digitsum = [](int x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
};

void Main() {
  ints(k);
  V<int> mp(1000000, big);
  mp[k] = digitsum(k);
  low_priority_queue<pair<int, int>> que;
  que.emplace(0, k);
  int ans = big;
  while (!que.empty()) {
    auto [cos, rem] = que.top();
    que.pop();
    if (mp[rem] < cos) continue;
    chmin(ans, digitsum(rem) + cos);
    rep(i, 10) {
      int x = rem + k * i;
      int nrem = x / 10;
      int ncos = cos + x % 10;
      if (chmin(mp[nrem], ncos)) que.emplace(ncos, nrem);
    }
  }
  wt(ans);
}
