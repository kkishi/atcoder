#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N);

  long long ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (i % 3 != 0 && i % 5 != 0) {
      ans += i;
    }
  }
  wt(ans);
}
