#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(i, n) {
    strings(w);
    if (i == n - 1) w.pop_back();
    if (w == "TAKAHASHIKUN" || w == "Takahashikun" || w == "takahashikun") {
      ++ans;
    }
  }
  wt(ans);
}
