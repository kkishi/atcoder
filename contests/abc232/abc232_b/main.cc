#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    strings(s, t);
    rep(i, 26) {
      bool ok = true;
      rep(j, sz(t)) if ((s[j] - 'a') != (t[j] - 'a' + i) % 26) ok = false;
      if (ok) return true;
    }
    return false;
  }());
}
