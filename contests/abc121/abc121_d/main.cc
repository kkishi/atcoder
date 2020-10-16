#include <bits/stdc++.h>

#include "atcoder.h"

int y(int x) {
  switch (x % 4) {
    case 0:
      return x;
    case 1:
      return 1;
    case 2:
      return x + 1;
    default:
      return 0;
  }
}

void Main() {
  ints(a, b);
  wt(y(b) ^ y(a - 1));
}
