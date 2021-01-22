#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y);
  map<int, int> dp;
  wt(Fix([&](auto rec, int y) -> int {
    auto [it, ok] = dp.insert({y, abs(x - y)});
    if (!ok) return it->second;
    if (x < y) {
      if (even(y)) {
        chmin(it->second, rec(y / 2) + 1);
      } else {
        chmin(it->second, min(rec(y - 1), rec(y + 1)) + 1);
      }
    }
    return it->second;
  })(y));
}
