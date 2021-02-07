#include <bits/stdc++.h>

#include "atcoder.h"
#include "factors.h"

void Main() {
  ints(n, p);
  int ans = 1;
  for (auto [k, v] : Factors(p)) rep(i, v / n) ans *= k;
  wt(ans);
}
