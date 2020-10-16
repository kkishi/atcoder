#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  for (int i = 1; i * i <= n; ++i) chmax(ans, i * i);
  wt(ans);
}
