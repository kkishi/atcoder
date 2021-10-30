#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> next(n + 1, -1), prev(n + 1, -1);
  rep(q) {
    ints(c);
    if (c == 1) {
      ints(x, y);
      next[x] = y;
      prev[y] = x;
    } else if (c == 2) {
      ints(x, y);
      next[x] = -1;
      prev[y] = -1;
    } else if (c == 3) {
      ints(x);
      while (prev[x] != -1) x = prev[x];
      V<int> ans;
      while (x != -1) {
        ans.pb(x);
        x = next[x];
      }
      cout << sz(ans) << " ";
      wt(ans);
    }
  }
}
