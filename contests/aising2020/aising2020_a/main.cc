#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l, r, d);
  int ans = 0;
  for (int i = l; i <= r; ++i) {
    if (i % d == 0) ++ans;
  }
  wt(ans);
}
