#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#undef int
#include "bignum.h"
#define int i64

void Main() {
  int x, y;
  char sep;
  cin >> x >> sep >> y;

  // 1 / 2 <= x / y
  if (y > x * 2) {
    wt("Impossible");
    return;
  }

  bigint hi =
      BinarySearch<bigint>(1, numeric_limits<int>::max(), [&](bigint n) {
        // (n * (n + 1) / 2 - n) / n <= x / y
        return (n - 1) * y <= x * 2;
      });
  bigint lo =
      BinarySearch<bigint>(numeric_limits<int>::max(), 0, [&](bigint n) {
        // x / y <= (n * (n + 1) / 2 - 1) / n
        return x * 2 * n <= (n * (n + 1) - 2) * y;
      });
  dbg(lo, hi);
  assert(lo <= hi);
  assert(hi - lo < 10);

  bool ok = false;
  for (bigint n = lo; n <= hi; ++n) {
    bigint m = BinarySearch<bigint>(1, n + 1, [&](bigint m) {
      // x / y <= (n * (n + 1) / 2 - m) / n
      return x * 2 * n <= y * (n * (n + 1) - m * 2);
    });
    dbg(n, m);
    if (x * 2 * n == y * (n * (n + 1) - m * 2)) {
      ok = true;
      wt(n, m);
    }
  }
  if (!ok) wt("Impossible");
}
