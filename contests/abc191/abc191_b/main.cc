#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  a.erase(remove(all(a), x), a.end());
  wt(a);
}
