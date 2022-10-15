#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int x = 1;
  rep(i, n) x *= i + 1;
  wt(x);
}
