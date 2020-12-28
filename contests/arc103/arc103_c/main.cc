#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int n = sz(s);
  auto ok = [&] {
    if (s.back() == '1') return false;
    rep(i, sz(s) - 1) if (s[i] != s[n - 2 - i]) return false;
    if (s[0] != '1') return false;
    return true;
  };
  if (!ok()) {
    wt(-1);
    return;
  }
  int last = 1;
  rep(i, n - 1) {
    int curr = i + 2;
    wt(last, curr);
    if (s[i] == '1') {
      last = curr;
    }
  }
}
