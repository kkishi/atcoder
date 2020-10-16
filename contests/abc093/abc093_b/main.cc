#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, k);
  for (int i = a; i <= b;) {
    wt(i);
    ++i;
    if (i > b) break;
    if (b - i < k) continue;
    if (i - a >= k) i = b - k + 1;
  }
}
