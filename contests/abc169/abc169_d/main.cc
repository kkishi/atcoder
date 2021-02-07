#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

void Main() {
  ints(n);
  int ans = 0;
  for (auto [_, x] : Factors(n)) {
    for (int i = 1; i <= x; ++i) {
      x -= i;
      ++ans;
    }
  }
  wt(ans);
}
