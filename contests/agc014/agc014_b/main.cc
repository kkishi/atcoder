#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> cnt(n);
  rep(m) {
    ints(a, b);
    ++cnt[a - 1];
    ++cnt[b - 1];
  }
  each(c, cnt) if (!even(c)) {
    wt("NO");
    return;
  }
  wt("YES");
}
