#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(s, a, b);
  if (s <= a) {
    wt(250);
  } else {
    wt(250 + div_ceil(s - a, b) * 100);
  }
}
