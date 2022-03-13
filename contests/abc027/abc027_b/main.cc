#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int tot = accumulate(a);
  if (tot % n != 0) {
    wt(-1);
    return;
  }
  int m = tot / n;
  int i = 0;
  int ans = 0;
  while (i < n) {
    int x = a[i];
    int j = i + 1;
    while (x != m * (j - i)) {
      x += a[j];
      ++j;
    }
    ans += j - i - 1;
    i = j;
  }
  wt(ans);
}
