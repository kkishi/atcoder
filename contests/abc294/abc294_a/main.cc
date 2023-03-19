#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> ans;
  rep(n) {
    ints(a);
    if (even(a)) ans.eb(a);
  }
  wt(ans);
}
