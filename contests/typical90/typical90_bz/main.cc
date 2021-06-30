#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> cnt(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    if (a > b) swap(a, b);
    ++cnt[b];
  }
  wt(count(all(cnt), int(1)));
}
