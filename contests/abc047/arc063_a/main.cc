#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = 0;
  rep(i, sz(s) - 1) if (s[i] != s[i + 1])++ ans;
  wt(ans);
}
