#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  each(e, a) if (e > 10) ans += e - 10;
  wt(ans);
}
