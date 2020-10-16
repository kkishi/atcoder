#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> r(n), b(n);
#define x first
#define y second
  rep(i, n) cin >> r[i].x >> r[i].y;
  rep(i, n) cin >> b[i].x >> b[i].y;
  sort(all(r));
  sort(all(b));
  int ans = 0;
  set<int> ry;
  auto ri = r.begin(), bi = b.begin();
  rep(x, 2 * n) {
    for (; ri != r.end() && ri->x <= x; ++ri) {
      ry.insert(ri->y);
    }
    for (; bi != b.end() && bi->x <= x; ++bi) {
      auto it = ry.lower_bound(bi->y);
      if (it != ry.begin()) {
        --it;
        ry.erase(it);
        ++ans;
      }
    }
  }
  wt(ans);
}
