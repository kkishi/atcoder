#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> l(2 * n);
  cin >> l;
  sort(all(l));
  int ans = 0;
  rep(i, n) ans += l[i * 2];
  wt(ans);
}
