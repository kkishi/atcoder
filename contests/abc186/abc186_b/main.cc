#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<int> a(h * w);
  cin >> a;
  int m = min(a);
  int ans = 0;
  each(ai, a) ans += ai - m;
  wt(ans);
}
