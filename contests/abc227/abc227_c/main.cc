#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  for (int a = 1; a * a * a <= n; ++a) {
    for (int b = a; a * b * b <= n; ++b) {
      ans += max(0, n / (a * b) - b + 1);
    }
  }
  wt(ans);
}
