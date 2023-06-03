#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a);
  int h = div_ceil(n, 2);
  for (int i = h; i < n; ++i) {
    if (a[i - h] >= a[i] || a[i] <= a[i - h + 1]) return false;
  }
  return true;
}
