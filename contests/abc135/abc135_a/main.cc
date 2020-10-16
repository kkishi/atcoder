#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  if (a == b) {
    wt(0);
  } else if ((a + b) % 2 == 0) {
    wt((a + b) / 2);
  } else {
    wt("IMPOSSIBLE");
  }
}
