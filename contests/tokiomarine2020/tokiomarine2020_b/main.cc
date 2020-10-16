#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, v, b, w, t);
  if (w >= v) {
    wt("NO");
    return;
  }
  if (abs(a - b) <= t * abs(v - w)) {
    wt("YES");
  } else {
    wt("NO");
  }
}
