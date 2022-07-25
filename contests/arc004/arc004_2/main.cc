#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> d(n);
  cin >> d;
  int sum = accumulate(d);
  int ma = max(d);
  wt(sum);
  wt(max(0, ma * 2 - sum));
}
