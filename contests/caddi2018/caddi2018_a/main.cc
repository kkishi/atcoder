#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

void Main() {
  ints(n, p);
  map<int, int> fs = Factorize(p);
  int ans = 1;
  for (auto [k, v] : fs) rep(i, v / n) ans *= k;
  wt(ans);
}
