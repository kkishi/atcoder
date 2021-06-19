#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int x = n * 108 / 100;
  if (x < 206) {
    wt("Yay!");
  } else if (x == 206) {
    wt("so-so");
  } else {
    wt(":(");
  }
}
