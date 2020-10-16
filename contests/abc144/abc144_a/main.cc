#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  if (1 <= a && a <= 9 && 1 <= b && b <= 9) {
    wt(a * b);
  } else {
    wt(-1);
  }
}
