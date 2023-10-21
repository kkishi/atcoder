#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> cnt(24);
  rep(n) {
    ints(w, x);
    rep(i, 9, 18) cnt[(i + x) % 24] += w;
  }
  wt(max(cnt));
}
