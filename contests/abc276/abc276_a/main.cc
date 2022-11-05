#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = -1;
  rep(i, sz(s)) if (s[i] == 'a') ans = i + 1;
  wt(ans);
}
