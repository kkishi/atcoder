#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<int, int> memo;
  wt(Fix([&](auto f, int k) -> int {
    if (k == 0) return 1;
    if (memo.count(k)) return memo[k];
    return memo[k] = f(k / 2) + f(k / 3);
  })(n));
}
