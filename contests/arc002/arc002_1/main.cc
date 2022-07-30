#include <bits/stdc++.h>

#include "atcoder.h"

int leap(int y) {
  if (y % 400 == 0) return true;
  if (y % 100 == 0) return false;
  if (y % 4 == 0) return true;
  return false;
}

void Main() {
  ints(y);
  wt(leap(y) ? "YES" : "NO");
}
