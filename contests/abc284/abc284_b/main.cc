#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    V<int> a(n);
    cin >> a;
    int ans = 0;
    each(e, a) if (!even(e))++ ans;
    wt(ans);
  }
}
