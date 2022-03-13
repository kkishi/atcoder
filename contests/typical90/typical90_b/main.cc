#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> ans;
  rep(mask, 1 << n) {
    bool ok = true;
    int x = 0;
    string s;
    rep(i, n) {
      if (hasbit(mask, i)) {
        --x;
        if (x < 0) ok = false;
        s += ')';
      } else {
        ++x;
        s += '(';
      }
    }
    if (x) ok = false;
    if (ok) ans.pb(s);
  }
  sort(ans);
  each(e, ans) wt(e);
}
