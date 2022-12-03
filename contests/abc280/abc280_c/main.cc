#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  rep(i, sz(s)) {
    if (s[i] != t[i]) {
      wt(i + 1);
      return;
    }
  }
  wt(sz(t));
}
