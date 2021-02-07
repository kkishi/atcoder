#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y);
  if (y == 0) {
    wt("ERROR");
  } else {
    int z = x * 100 / y;
    cout << setprecision(2);
    wt((double)z / 100);
  }
}
