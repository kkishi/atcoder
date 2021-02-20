#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x);
  ++x;
  int ans = 1;
  while (x % 100) {
    ++x, ++ans;
  }
  wt(ans);
}
