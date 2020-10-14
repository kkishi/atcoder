#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(r, b, x, y);
  wt(BinarySearch<int>(0, max(r, b), [&](int k) {
    if (r < k || b < k) return false;
    return (r - k) / (x - 1) + (b - k) / (y - 1) >= k;
  }));
}
