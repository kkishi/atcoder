#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "bit.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  wt(BinarySearch<int>(0, 1000'000'001, [&](int x) {
    // Count the number of medians larger than or equal to x
    BIT<int> bit(2 * n + 1);  // Covers [-n, n].
    int y = 0;
    int z = 0;
    bit.Add(n, 1);
    rep(i, n) {
      if (a[i] < x) {
        --z;
      } else {
        ++z;
      }
      int nz = z + n;
      y += bit.Sum(nz);
      bit.Add(nz, 1);
    }
#if DEBUG
    int Y = 0;
    rep(i, n) {
      int z = 0;
      rrep(j, i + 1) {
        if (a[j] < x) {
          --z;
        } else {
          ++z;
        }
        if (z >= 0) ++Y;
      }
    }
    assert(Y == y);
#endif
    return y >= (n * (n + 1) / 2 + 1) / 2;
  }));
}
