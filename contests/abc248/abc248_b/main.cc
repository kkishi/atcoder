#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, k);
  int ans = 0;
  while (a < b) {
    ++ans;
    a *= k;
  }
  wt(ans);
}
