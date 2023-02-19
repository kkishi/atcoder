#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  int ans = 0;
  each(e, b) ans += a[e - 1];
  wt(ans);
}
