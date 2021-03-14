#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  for (int ten = 1000; ten <= n; ten *= 1000) {
    ans += n - ten + 1;
  }
  wt(ans);
}
