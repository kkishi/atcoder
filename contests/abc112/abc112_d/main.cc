#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

void Main() {
  ints(n, m);
  int ans = 1;
  each(d, Divisors(m)) if (m / d >= n) chmax(ans, d);
  wt(ans);
}
