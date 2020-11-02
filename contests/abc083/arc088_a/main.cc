#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y);
  int i = 0;
  while (x * 2 <= y) {
    x *= 2;
    ++i;
  }
  wt(i + 1);
}
