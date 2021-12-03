#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  string t = "oxx";
  wt([&] {
    rep(i, 3) {
      bool ok = true;
      rep(j, sz(s)) if (s[j] != t[(i + j) % 3]) ok = false;
      if (ok) return true;
    }
    return false;
  }());
}
