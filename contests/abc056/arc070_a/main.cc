#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x);
  for (int i = 1;; ++i) {
    if (i * (i + 1) / 2 >= x) {
      wt(i);
      return;
    }
  }
}
