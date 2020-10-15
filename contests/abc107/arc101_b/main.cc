#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  wt(BinarySearch<int>(0, 1000'000'001, [&](int x) {
    // Count the number of medians larger than or equal to x
    stack<int> u, b;
    int c = 0;
    int us = 0, bs = 0;
    int y = 0;
    rep(i, n) {
      ++c;
      if (a[i] < x) {
        b.push(c);
        bs += c;
        if (u.empty()) {
          c = 0;
        } else {
          c = u.top();
          u.pop();
          us -= c;
        }
      } else {
        u.push(c);
        us += c;
        if (b.empty()) {
          c = 0;
        } else {
          c = b.top();
          b.pop();
          bs -= c;
        }
      }
      y += us + c;
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
