#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, n);
  int l = lcm(a, b);
  wt(div_ceil(n, l) * l);
}
