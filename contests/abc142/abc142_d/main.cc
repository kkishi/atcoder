#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

void Main() {
  ints(a, b);
  wt(Factors(gcd(a, b)).size() + 1);
}
