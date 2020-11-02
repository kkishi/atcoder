#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int m = 2025 - n;
  for (int i = 1; i <= 9; ++i) {
    if (m % i == 0 && m / i <= 9) {
      printf("%d x %d\n", i, m / i);
    }
  }
}
