#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  strings(s);
  int ans = 0;
  rep(i, n - 1) if (s[i] == s[i + 1])++ ans;
  wt(min(ans + k * 2, n - 1));
}
