#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(w, h);
  V<int> p(w), q(h);
  cin >> p >> q;
  int inf = numeric_limits<int>::max() / 10;
  p.push_back(inf);
  q.push_back(inf);
  sort(all(p));
  sort(all(q));
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
