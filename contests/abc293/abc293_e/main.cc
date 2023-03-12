#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"

void Main() {
  ints(a, x, m);
  if (a == 1) {
    wt(a * x % m);
    return;
  }
  int y = Pow(a, x, m * (a - 1)) - 1;
  if (y < 0) y += m;
  wt(y / (a - 1));
}
