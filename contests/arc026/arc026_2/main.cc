#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

void Main() {
  ints(n);
  V<int> ds = Divisors(n);
  int sum = accumulate(all(ds), -n);
  wt(sum == n ? "Perfect" : sum < n ? "Deficient" : "Abundant");
}
