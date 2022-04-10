#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([]() {
    ints(n);
    V<string> s(n), t(n);
    rep(i, n) cin >> s[i] >> t[i];
    rep(i, n) {
      bool S = true, T = true;
      rep(j, n) if (j != i) {
        if (s[i] == s[j] || s[i] == t[j]) S = false;
        if (t[i] == s[j] || t[i] == t[j]) T = false;
      }
      if (!S && !T) return false;
    }
    return true;
  }());
}
