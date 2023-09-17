#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  auto ok = [](string s) {
    string t = s;
    reverse(t);
    return t == s;
  };
  int ans = -big;
  rep(i, sz(s)) {
    rep(j, 1, sz(s) + 1 - i) {
      if (ok(s.substr(i, j))) chmax(ans, j);
    }
  }
  wt(ans);
}
