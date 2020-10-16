#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(d, n);
  int cnt = 0;
  for (int i = 1;; ++i) {
    int j = i;
    int cnt2 = 0;
    while (j % 100 == 0) {
      j /= 100;
      ++cnt2;
    }
    if (cnt2 == d) ++cnt;
    if (cnt == n) {
      wt(i);
      return;
    }
  }
}
