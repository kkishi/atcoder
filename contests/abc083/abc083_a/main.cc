#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, d);
  int sign = a + b - (c + d);
  wt(sign > 0 ? "Left" : sign == 0 ? "Balanced" : "Right");
}
