#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, d);
  wt(max({a * c, a * d, b * c, b * d}));
}
