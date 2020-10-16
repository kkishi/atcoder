#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  int ans = 0;
  rep(i, 3) ans += s[i] == t[i];
  wt(ans);
}
