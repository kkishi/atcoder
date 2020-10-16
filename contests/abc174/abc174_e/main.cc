#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

using ld = long double;
const ld eps = 0.0000000001;

void Main() {
  ints(n, k);
  V<ld> a(n);
  cin >> a;
  ld ans = BinarySearch<ld>(*max_element(all(a)), 0, [&](ld mid) {
    int cuts = 0;
    rep(i, n) cuts += (a[i] / mid) - eps;
    return cuts <= k;
  });
  wt(int(ceil(ans) + eps));
}
