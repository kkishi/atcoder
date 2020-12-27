#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  VV<int> b(100001);
  rep(i, n) b[a[i]].push_back(i);

  int ans = 1;
  int curr = 0;
  rep(i, 100001) {
    if (b[i].empty()) continue;
    auto it = lower_bound(all(b[i]), curr);
    if (it != b[i].begin()) {
      ++ans;
      curr = *(it - 1);
    } else {
      curr = b[i].back();
    }
  }
  if (curr == 0) --ans;
  wt(ans);
}
