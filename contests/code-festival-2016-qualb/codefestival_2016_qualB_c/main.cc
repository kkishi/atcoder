#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(w, h);
  V<int> p(w), q(h);
  cin >> p >> q;
  p.pb(big);
  q.pb(big);
  sort(p);
  sort(q);
  int x = w + 1;
  int y = h + 1;
  auto pit = p.begin();
  auto qit = q.begin();
  int ans = 0;
  rep(w + h) {
    if (*pit < *qit) {
      ans += y * *pit;
      --x;
      ++pit;
    } else {
      ans += x * *qit;
      --y;
      ++qit;
    }
  }
  wt(ans);
}
