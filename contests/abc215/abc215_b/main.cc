#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int k = 0;
  int x = 1;
  while (x * 2 <= n) {
    ++k;
    x *= 2;
  }
  wt(k);
}
