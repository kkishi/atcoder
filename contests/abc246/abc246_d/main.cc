#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  const int N = 1000000;
  int ans = big;
  rep(a, N) {
    auto f = [](int a, int b) {
      return a * a * a + a * a * b + a * b * b + b * b * b;
    };
    int b = BinarySearch<int>(N, -1, [&](int x) { return f(a, x) >= n; });
    chmin(ans, f(a, b));
  }
  wt(ans);
}
