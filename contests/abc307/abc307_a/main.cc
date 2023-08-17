#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> ans;
  rep(n) {
    V<int> a(7);
    cin >> a;
    ans.eb(accumulate(a));
  }
  wt(ans);
}
