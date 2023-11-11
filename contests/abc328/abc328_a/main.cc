#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> s(n);
  cin >> s;
  int ans = 0;
  each(e, s) if (e <= x) ans += e;
  wt(ans);
}
