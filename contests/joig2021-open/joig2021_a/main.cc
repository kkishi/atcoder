#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  int d = max({a, b, c});
  wt(3 * d - (a + b + c));
}
