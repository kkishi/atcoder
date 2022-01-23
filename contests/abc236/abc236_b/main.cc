#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n * 4);
  cin >> a;
  int tot = 0;
  rep(i, n) tot += (i + 1) * 4;
  each(e, a) tot -= e;
  wt(tot);
}
