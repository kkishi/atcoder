#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  rep(i, n) {
    string t = s.substr(i);
    int ans = 0;
    rep(j, n) {
      string u = s.substr(j);
      int l = min(sz(t), sz(u));
      rrep(k, 1, l + 1) if (t.substr(0, k) == u.substr(0, k)) {
        ans += k;
        break;
      }
    }
    wt(ans);
  }
}
