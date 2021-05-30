#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  if (a == b) {
    wt(c);
    return;
  }
  if (b == c) {
    wt(a);
    return;
  }
  if (c == a) {
    wt(b);
    return;
  }
  wt(0);
}
