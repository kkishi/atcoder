#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, c);
  int y = 8 - r;
  int x = -8 + c;
  wt(even(max(abs(x), abs(y))) ? "white" : "black");
}
