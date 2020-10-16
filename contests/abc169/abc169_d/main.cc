#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

void Main() {
  ints(N);
  map<int, int> m = Factorize(N);
  int ans = 0;
  for (const auto p : m) {
    dbg(p.first, p.second);
    int x = p.second;
    for (int i = 1; i <= x; ++i) {
      x -= i;
      ++ans;
      dbg(i, x);
    }
  }
  wt(ans);
}
