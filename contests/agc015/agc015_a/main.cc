#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b);
  if (a > b || n == 1 && a != b) {
    wt(0);
    return;
  }
  wt((b * (n - 1) + a) - (a * (n - 1) + b) + 1);
}
