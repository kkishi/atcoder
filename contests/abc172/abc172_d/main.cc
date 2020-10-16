#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> p(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      ++p[j];
    }
    ans += i * p[i];
  }
  wt(ans);
}
