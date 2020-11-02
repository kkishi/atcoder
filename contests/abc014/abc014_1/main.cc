#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  int r = a % b;
  wt(r == 0 ? 0 : b - r);
}
