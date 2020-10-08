#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k, a, b);
  if (b < a + 2) {
    wt(k + 1);
    return;
  }
  if (k <= a - 1) {
    wt(k + 1);
    return;
  }
  int c = a;
  k -= a - 1;
  int l = k / 2;
  int d = b - a;
  c += d * l;
  wt(c + (k % 2));
}
