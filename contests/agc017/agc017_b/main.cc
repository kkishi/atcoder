#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b, c, d);
  b = abs(b - a);
  --n;
  rep(i, n / 2) {
    int l = -d * i + c * (n - i);
    int h = -c * i + d * (n - i);
    if (l <= b && b <= h) {
      wt("YES");
      return;
    }
  }
  wt("NO");
}
