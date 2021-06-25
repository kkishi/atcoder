#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  int ans = 0;
  rep(i, n) ans += int_pow(2, i) * (s[i] - 'a');
  wt(ans);
}
