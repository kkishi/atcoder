#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, n);
  map<pair<int, int>, int> mp;
  rep(n) {
    ints(a, b);
    ++mp[{a, b}];
  }
  int ans = 0;
  each(e, _, mp) {
    auto [a, b] = e;
    rep(mir, a - 2, a + 1) {
      rep(mic, b - 2, b + 1) {
        int sum = 0;
        rep(r, 3) rep(c, 3) {
          auto it = mp.find({mir + r, mic + c});
          if (it != mp.end()) sum += it->second;
        }
        chmax(ans, sum);
      }
    }
  }
  wt(ans);
}
