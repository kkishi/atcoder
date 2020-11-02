#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> a(3);
  cin >> a;
  sort(all(a));
  wt(a[2] - a[0]);
}
