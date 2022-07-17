#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> p(n);
  cin >> p;
  each(e, p)-- e;
  V<int> ans(n, -1);
  V<int> next(n, -1);
  V<int> size(n, -1);
  set<int> visible;
  rep(i, n) {
    auto it = visible.lower_bound(p[i]);
    if (it == visible.end()) {
      visible.insert(p[i]);
      size[p[i]] = 1;
    } else {
      int x = *it;
      visible.erase(it);
      visible.insert(p[i]);
      next[p[i]] = x;
      size[p[i]] = size[x] + 1;
    }
    if (size[p[i]] == k) {
      visible.erase(p[i]);
      for (int x = p[i]; x != -1; x = next[x]) {
        ans[x] = i + 1;
      }
    }
  }
  each(e, ans) wt(e);
}
