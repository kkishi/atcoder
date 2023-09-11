#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, m);
  V<int> l(n);
  cin >> l;
  wt(BinarySearch<int>(accumulate(l) + n - 1, max(l) - 1, [&](int x) {
    int cnt = 1;
    int sum = l[0];
    rep(i, 1, n) {
      if (sum + 1 + l[i] <= x) {
        sum += 1 + l[i];
      } else {
        ++cnt;
        sum = l[i];
      }
    }
    return cnt <= m;
  }));
}
