#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  if (a >= 13) {
    wt(b);
  } else if (a >= 6) {
    wt(b / 2);
  } else {
    wt(0);
  }
}
