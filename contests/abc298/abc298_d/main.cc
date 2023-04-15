#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  mint ans = 1;
  deque<int> que = {1};
  ints(q);
  rep(q) {
    ints(tp);
    if (tp == 1) {
      ints(x);
      ans *= 10;
      ans += x;
      que.push_back(x);
    } else if (tp == 2) {
      ans -= mint(que.front()) * mint(10).Pow(sz(que) - 1);
      que.pop_front();
    } else {
      wt(ans);
    }
  }
}
