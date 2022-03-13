#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> d(n);
  cin >> d;
  sort(d);
  wt(d[n / 2] - d[n / 2 - 1]);
}
