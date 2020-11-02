#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N);
  int n = N;
  int f = 0;
  while (n) {
    f += n % 10;
    n /= 10;
  }
  wt(N % f == 0);
}
