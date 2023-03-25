#include <bits/stdc++.h>

#include "atcoder.h"

int Solve(const string& s, int x) {
  int ans = 0;
  rep(i, 1, x + 1) {
    string t = to_string(i);
    rep(i, sz(t)) if (t.substr(i, sz(s)) == s)++ ans;
  }
  return ans;
}

void Main() {
  ints(t);
  rep(t) {
    strings(s);
    ints(l, r);
    wt(Solve(s, r) - Solve(s, l - 1));
  }
}
