#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x);
  int rem = x % 11;
  wt(x / 11 * 2 + (rem == 0 ? 0 : rem <= 6 ? 1 : 2));
}
