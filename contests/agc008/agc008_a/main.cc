#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y);
  int ans = 0;
  if (abs(x) == abs(y)) {
    if (x != y) ++ans;
  } else if (abs(x) < abs(y)) {
    if (x < 0) ++ans;
    if (y < 0) ++ans;
  } else {
    if (x > 0) ++ans;
    if (y > 0) ++ans;
  }
  wt(ans + abs(abs(x) - abs(y)));
}
