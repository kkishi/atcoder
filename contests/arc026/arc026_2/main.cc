#include <bits/stdc++.h>

#include "atcoder.h"
#include "divisors.h"

void Main() {
  ints(n);
  V<int> ds = Divisors(n);
  int sum = accumulate(ds) - n;
  wt(sum == n ? "Perfect" : sum < n ? "Deficient" : "Abundant");
}
