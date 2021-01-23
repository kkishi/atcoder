#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int i = 0;
  int ans = 0;
  while (i < n) {
    int j = i + 1;
    while (j + 1 < n) {
      if (a[i] <= a[j] && a[j] <= a[j + 1] ||
          a[i] >= a[j] && a[j] >= a[j + 1]) {
        ++j;
        continue;
      }
      break;
    }
    ++ans;
    i = j + 1;
  }
  wt(ans);
}
