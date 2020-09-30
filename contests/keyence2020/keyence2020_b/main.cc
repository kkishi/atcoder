#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> r;
  rep(n) {
    ints(x, l);
    r.push_back({x + l, x - l});
  }
  sort(all(r));
  int ans = 1;
  int last = r[0].first;
  rep(i, 1, n) if (r[i].second >= last) {
    ++ans;
    last = r[i].first;
  }
  wt(ans);
}
