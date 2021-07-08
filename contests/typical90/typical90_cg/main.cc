#include <bits/stdc++.h>

#include "atcoder.h"
#include "factors.h"

void Main() {
  ints(k);
  int ans = 0;
  for (int i = 1; i * i <= k; ++i) {
    if (k % i != 0) continue;
    int k_i = k / i;
    for (int j = i; j * j <= k_i; ++j) {
      if (k_i % j != 0) continue;
      ++ans;
    }
  }
  wt(ans);
}
