#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l1, r1, l2, r2);
  if (r1 <= l2 || r2 <= l1) {
    wt(0);
  } else {
    wt(min(r1, r2) - max(l1, l2));
  }
}
