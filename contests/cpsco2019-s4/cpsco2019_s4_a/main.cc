#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l, x);
  int y = x / l;
  int z = x % l;
  if (y & 1) z = l - z;
  wt(z);
}
