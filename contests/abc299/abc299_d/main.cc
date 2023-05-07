#include <bits/stdc++.h>

#include "atcoder_interactive.h"
#include "binary_search.h"

void Main() {
  ints(n);
  int x = BinarySearch<int>(0, n - 1, [](int x) {
    wt_flush("?", x + 1);
    ints(s);
    return s == 0;
  });
  wt_flush("!", x + 1);
}
