#include <bits/stdc++.h>

#include "atcoder.h"

int Solve() {
  strings(s);
  string t = "atcoder";
  if (t < s) {
    return 0;
  }
  int ans = big;
  rep(i, min(sz(t), sz(s))) {
    rep(j, i, sz(s)) {
      if (t[i] < s[j]) {
        chmin(ans, j - i);
      }
    }
    if (s[i] != t[i]) break;
  }
  return ans == big ? -1 : ans;
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}
