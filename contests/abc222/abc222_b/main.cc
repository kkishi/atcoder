#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, p);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  each(e, a) if (e < p)++ ans;
  wt(ans);
}
