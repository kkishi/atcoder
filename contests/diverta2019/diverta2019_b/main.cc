#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, g, b, n);
  int ans = 0;
  for (int i = 0; i * r <= n; ++i) {
    for (int j = 0; i * r + j * g <= n; ++j) {
      if ((n - (i * r + j * g)) % b == 0) ++ans;
    }
  }
  wt(ans);
}
