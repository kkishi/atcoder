#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<bool> v(n);
  V<int> cnt(n, 1);
  v[0] = true;
  rep(m) {
    ints(x, y);
    --x, --y;
    if (v[x]) v[y] = true;
    --cnt[x];
    ++cnt[y];
    if (cnt[x] == 0) v[x] = false;
  }
  wt(count(all(v), true));
}
