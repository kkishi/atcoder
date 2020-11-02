#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, k);
  for (int i = min(a, b);; --i) {
    if (a % i + b % i == 0) {
      --k;
      if (k == 0) {
        wt(i);
        return;
      }
    }
  }
}
