#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<pair<int, int>> v;
  rep(n) {
    ints(a, b);
    v.eb(a, b);
  }
  sort(v, greater{});
  int ans = k;
  while (!v.empty() && v.back().first <= ans) {
    ans += v.back().second;
    v.pop_back();
  }
  wt(ans);
}
