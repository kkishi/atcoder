#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(n);
  rep(i, 10) {
    string m = string(i, '0') + n;
    bool ok = true;
    rep(j, sz(m)) if (m[j] != m[sz(m) - 1 - j]) ok = false;
    if (ok) {
      wt("Yes");
      return;
    }
  }
  wt("No");
}
