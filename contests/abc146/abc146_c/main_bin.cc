#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

int digits(int x) { return x == 0 ? 0 : 1 + digits(x / 10); }

void Main() {
  ints(a, b, x);
  wt(BinarySearch<int>(0, 1000000001,
                       [&](int y) { return a * y + b * digits(y) <= x; }));
}
