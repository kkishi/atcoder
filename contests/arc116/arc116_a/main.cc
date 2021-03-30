#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    int cnt = 0;
    while (n % 2 == 0) {
      n /= 2;
      ++cnt;
    }
    if (cnt == 0) {
      wt("Odd");
    } else if (cnt == 1) {
      wt("Same");
    } else {
      wt("Even");
    }
  }
}
