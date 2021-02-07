#include <bits/stdc++.h>

#include "atcoder.h"
#include "divisors.h"

void Main() {
  ints(n);
  auto digits = [](int x) {
    int ret = 1;
    while (x > 9) {
      x /= 10;
      ++ret;
    }
    return ret;
  };
  int ans = big;
  each(d, Divisors(n)) chmin(ans, max(digits(d), digits(n / d)));
  wt(ans);
}
