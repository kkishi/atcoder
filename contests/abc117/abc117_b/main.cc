#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> l(n);
  cin >> l;
  int s = accumulate(l);
  bool ok = true;
  rep(i, n) if (s - l[i] <= l[i]) ok = false;
  wt(ok);
}
