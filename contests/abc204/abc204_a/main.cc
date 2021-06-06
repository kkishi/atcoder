#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y);
  if (x == y) {
    wt(x);
  } else {
    wt(3 - (x + y));
  }
}
