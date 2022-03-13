#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a);
  int l = 0, h = n - 1;
  int ans = a[h] - a[l];
  ++l, --h;
  while (l < h) {
    ans += a[h + 1] - a[l] + a[h] - a[l - 1];
    ++l, --h;
  }
  if (l == h) {
    ans += max(a[l + 1] - a[l], a[l] - a[l - 1]);
  }
  wt(ans);
}
