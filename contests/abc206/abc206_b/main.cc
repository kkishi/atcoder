#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int sum = 0;
  for (int i = 1;; ++i) {
    sum += i;
    if (sum >= n) {
      wt(i);
      return;
    }
  }
}
