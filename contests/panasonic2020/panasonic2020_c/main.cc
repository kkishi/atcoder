#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  int d = c - (a + b);
  wt(d > 0 && 4 * a * b < d * d);
}
