#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, a, b);
  if (b <= a) {
    wt("delicious");
  } else if (b - a <= x) {
    wt("safe");
  } else {
    wt("dangerous");
  }
}
