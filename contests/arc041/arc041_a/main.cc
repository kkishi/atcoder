#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y, k);
  if (y >= k) {
    wt(x + k);
  } else {
    wt(x + y - (k - y));
  }
}
