#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  int c = a + b;
  if (c >= 15 && b >= 8) {
    wt(1);
  } else if (c >= 10 && b >= 3) {
    wt(2);
  } else if (c >= 3) {
    wt(3);
  } else {
    wt(4);
  }
}
