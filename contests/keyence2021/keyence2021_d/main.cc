#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> ans{"AB"};
  rep(n - 1) {
    V<string> nans;
    int l = sz(ans[0]);
    nans.pb(string(l, 'A') + string(l, 'B'));
    each(a, ans) {
      nans.pb(a + a);
      string r = a;
      each(c, r) c = 'A' + 'B' - c;
      nans.pb(a + r);
    }
    swap(ans, nans);
  }
  wt(sz(ans));
  each(a, ans) wt(a);
}
