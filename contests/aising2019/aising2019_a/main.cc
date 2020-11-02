#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, h, w);
  int x = max(0, n - h + 1);
  int y = max(0, n - w + 1);
  wt(x * y);
}
