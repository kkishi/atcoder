#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(a, b, c);
  auto f = [&](double x) {
    const double pi = 3.14159265358979;
    return a * x + b * sin(c * x * pi);
  };
  wt(BinarySearch<double>(0, 200, [&](double x) { return f(x) < 100; }));
}
