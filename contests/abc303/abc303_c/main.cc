#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(n, m, h, k);
  strings(s);
  set<pair<int, int>> item;
  rep(m) {
    ints(x, y);
    item.emplace(x, y);
  }
  int x = 0, y = 0;
  each(e, s) {
    --h;
    if (h < 0) return false;
    if (e == 'R') ++x;
    if (e == 'L') --x;
    if (e == 'U') ++y;
    if (e == 'D') --y;
    if (h < k && item.count({x, y})) {
      h = k;
      item.erase({x, y});
    }
  }
  return true;
}
