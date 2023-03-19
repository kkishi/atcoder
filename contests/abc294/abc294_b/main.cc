#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  rep(h) {
    string ans;
    rep(w) {
      ints(a);
      ans += (a == 0 ? '.' : (char)('A' + a - 1));
    }
    wt(ans);
  }
}
