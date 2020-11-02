#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  int c = 1;
  int ans = 0;
  while (c < b) {
    ++ans;
    c += a - 1;
  }
  wt(ans);
}
