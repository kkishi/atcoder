#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k, q);
  V<int> a(k), l(q);
  cin >> a >> l;
  each(e, l) {
    --e;
    if (a[e] == n) continue;
    if (e == k - 1 || a[e] + 1 != a[e + 1]) ++a[e];
  }
  wt(a);
}
