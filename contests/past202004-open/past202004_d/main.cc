#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = 0;
  V<string> v{""};
  rep(3) {
    V<string> u;
    each(t, v) rep(i, 27) {
      char c = i < 26 ? ('a' + i) : '.';
      u.pb(t + c);
    }
    swap(u, v);
    each(t, v) {
      bool ok1 = false;
      rep(i, sz(s) - (sz(t) - 1)) {
        bool ok2 = true;
        rep(j, sz(t)) if (t[j] != '.' && t[j] != s[i + j]) ok2 = false;
        if (ok2) ok1 = true;
      }
      if (ok1) ++ans;
    }
  }
  wt(ans);
}
