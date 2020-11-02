#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  if (a > b) {
    wt(a * 2 - 1);
  } else if (a == b) {
    wt(a * 2);
  } else {
    wt(b * 2 - 1);
  }
}
