#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = -big;
  int ans_i;
  set<string> seen;
  rep(i, n) {
    strings(s);
    ints(t);
    if (!seen.insert(s).second) continue;
    if (chmax(ans, t)) ans_i = i;
  }
  wt(ans_i + 1);
}
