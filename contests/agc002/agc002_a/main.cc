#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  if (a <= 0 && 0 <= b) {
    wt("Zero");
    return;
  }
  if (b < 0) {
    if (!even(b - a + 1)) {
      wt("Negative");
      return;
    }
  }
  wt("Positive");
}
