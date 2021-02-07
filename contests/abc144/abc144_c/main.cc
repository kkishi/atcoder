#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

void Main() {
  ints(n);
  int ans = big;
  each(d, Divisors(n)) chmin(ans, (d - 1) + (n / d - 1));
  wt(ans);
}
