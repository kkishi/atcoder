#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    if (n == 2) {
      wt(1);
      continue;
    }
    set<int> st;
    for (int i = 2; i * i * i * i * i <= n; ++i) {
      bool ok = true;
      int j = n;
      while (j) {
        if (j % i >= 2) ok = false;
        j /= i;
      }
      if (ok) st.insert(i);
    }
    rep(mask, 1 << 5) {
      auto calc = [&](int x) {
        __int128_t sum = 0;
        rep(i, 5) {
          sum *= x;
          if (hasbit(mask, i)) sum += 1;
          if (sum > n) break;
        }
        return sum;
      };
      int x = BinarySearch<int>(2, n + 1, [&](int x) { return calc(x) <= n; });
      if (calc(x) == n) st.insert(x);
    }
    wt(sz(st));
  }
}
