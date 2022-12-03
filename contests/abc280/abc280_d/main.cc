#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "factors.h"

void Main() {
  ints(k);
  auto fs = Factors(k);
  int N = 1000000000000LL;
  int ans = -big;
  each(k, v, fs) {
    int x = BinarySearch<int>(N, 1, [&](int x) {
      int cnt = 0;
      int p = k;
      while (p <= x) {
        cnt += x / p;
        p *= k;
      }
      return cnt >= v;
    });
    chmax(ans, x);
  }
  wt(ans);
}
