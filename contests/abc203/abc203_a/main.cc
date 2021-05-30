#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  int s = a + b + c;
  if (a == b) {
    wt(s - a * 2);
    return;
  }
  if (b == c) {
    wt(s - b * 2);
    return;
  }
  if (c == a) {
    wt(s - a * 2);
    return;
  }
  wt(0);
}
