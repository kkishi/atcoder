#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> l(n);
  cin >> l;
  sort(l);
  wt(accumulate(l.rbegin(), l.rbegin() + k, 0));
}
