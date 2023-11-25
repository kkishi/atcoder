#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l);
  V<int> a(n);
  cin >> a;
  wt(count_if(all(a), [&](int x) { return x >= l; }));
}
