#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  strings(s);
  int ans = x;
  rep(i, sz(s)) {
    if (s[i] == 'x')
      ans = max(0, ans - 1);
    else
      ++ans;
  }
  wt(ans);
}
