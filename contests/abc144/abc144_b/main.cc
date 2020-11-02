#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  bool ok = false;
  for (int a = 1; a <= 9; ++a) {
    if (n % a == 0) {
      int b = n / a;
      if (1 <= b && b <= 9) {
        ok = true;
      }
    }
  }
  wt(ok);
}
