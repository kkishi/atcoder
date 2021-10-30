#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "numeric_sequence.h"

void Main() {
  ints(n, s, t, a, b);
  double e = BinarySearch<double>(0, big, [&](double e) {
    int i = min(t, max(0, floor(t - (b + e) / a)));
    double f = (i * (b + e) + a * ArithmeticProgressionSum<int>(0, 1, t - i) +
                (n - t) * (b + e)) /
               n;
    return e < f;
  });
  double ans = b + e;
  if (s <= t) chmin(ans, a * (t - s));
  wt(ans);
}
