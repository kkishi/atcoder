#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  int ans = BinarySearch<int>(0, big, [&](int x) {
    int cnt = 0;
    int rem = x;
    each(e, a) {
      rem -= min(x, e);
      if (rem <= 0) {
        ++cnt;
        rem += x;
      }
    }
    return cnt >= k;
  });
  wt(ans);
}
