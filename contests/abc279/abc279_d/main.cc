#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  rd(double, a, b);
  auto f = [&](int x) { return a / sqrt(1 + x) + b * x; };
  auto g = [&](int x) { return f(x + 1) < f(x); };
  if (!g(0)) {
    wt(f(0));
  } else {
    int x = BinarySearch<int>(0, 1000000000000LL, [&](int x) { return g(x); });
    wt(f(x + 1));
  }
}
