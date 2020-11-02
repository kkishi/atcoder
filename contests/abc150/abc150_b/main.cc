#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  int ans = 0;
  rep(i, s.size() - 2) {
    if (s.substr(i, 3) == "ABC") ++ans;
  }
  wt(ans);
}
