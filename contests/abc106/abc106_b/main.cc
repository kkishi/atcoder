#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    int cnt = 0;
    for (int j = 1; j <= i; ++j) {
      if (i % j == 0) ++cnt;
    }
    if (cnt == 8) ++ans;
  }
  wt(ans);
}
