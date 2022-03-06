#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, x);
  if (x <= a) {
    wt(1);
  } else if (x <= b) {
    wt(double(c) / (b - a));
  } else {
    wt(0);
  }
}
