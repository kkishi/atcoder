#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  bool ok = true;
  rep(i, s.size()) {
    if (i % 2 == 1) {
      if (s[i] == 'R') {
        ok = false;
      }
    } else {
      if (s[i] == 'L') {
        ok = false;
      }
    }
  }
  wt(ok);
}
