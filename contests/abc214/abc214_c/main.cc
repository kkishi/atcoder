#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> s(n), t(n);
  cin >> s >> t;
  int mini = big;
  rep(I, n * 2) {
    mini = min(t[I % n], mini + s[(I - 1 + n) % n]);
    if (I >= n) wt(mini);
  }
}
