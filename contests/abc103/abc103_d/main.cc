#include <bits/stdc++.h>

#include "atcoder.h"

using P = pair<int, int>;

void Main() {
  ints(n, m);
  vector<P> v;
  rep(i, m) {
    ints(a, b);
    v.pb({b, a});
  }
  sort(all(v));
  int ans = 0;
  int last = 0;
  for (auto [b, a] : v) {
    if (a < last && last <= b) continue;
    ++ans;
    last = b;
  }
  wt(ans);
}
