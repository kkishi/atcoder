#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int k = 1;
  rep(i, 2, n + 1) k *= i / gcd(k, i);
  wt(k + 1);
}
