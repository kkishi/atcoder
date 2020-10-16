#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<int, int> m;
  rep(n) {
    ints(a);
    ++m[a];
  }
  auto l = m.begin(), r = prev(m.end());
  while (true) {
    while (l != r && l->second == 1) ++l;
    while (r != l && r->second == 1) --r;
    if (l != r) {
      --l->second;
      --r->second;
    } else {
      if (l->second >= 2) {
        l->second -= 2;
      } else {
        break;
      }
    }
  }
  int ans = 0;
  for (auto [_, v] : m) ans += v;
  wt(ans);
}
