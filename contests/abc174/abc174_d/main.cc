#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(c);
  int l = 0, r = n - 1;
  int ans = 0;
  while (l < r) {
    if (c[l] == 'R') {
      ++l;
      continue;
    }
    if (c[r] == 'W') {
      --r;
      continue;
    }
    dbg(l, r);
    ++ans;
    ++l;
    --r;
  }
  wt(ans);
}
