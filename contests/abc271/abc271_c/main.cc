#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> mp;
  each(e, a)++ mp[e];
  wt(BinarySearch<int>(0, n + 1, [&](int x) {
    int rem = 0;
    each(k, v, mp) rem += max(0, v - (k <= x));
    rep(i, x) if (mp[i + 1] == 0) rem -= 2;
    return rem >= 0;
  }));
}
