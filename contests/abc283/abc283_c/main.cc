#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = 0;
  while (!s.empty()) {
    if (sz(s) >= 2 && s.substr(sz(s) - 2) == "00") {
      ++ans;
      rep(2) s.pop_back();
    } else {
      ++ans;
      s.pop_back();
    }
  }
  wt(ans);
}
