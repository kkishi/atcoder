#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(1 << n);
  cin >> a;
  int x = *max_element(a.begin(), a.begin() + (1 << (n - 1)));
  int y = *max_element(a.begin() + (1 << (n - 1)), a.end());
  int z = min(x, y);
  rep(i, 1 << n) if (a[i] == z) wt(i + 1);
}
