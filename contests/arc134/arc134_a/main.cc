#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l, w);
  V<int> a(n);
  cin >> a;
  sort(a);
  int x = 0;
  int ans = 0;
  each(e, a) {
    if (x < e) ans += div_ceil(e - x, w);
    x = e + w;
  }
  wt(ans + div_ceil(l - x, w));
}
