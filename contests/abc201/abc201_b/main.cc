#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, string>> v;
  rep(n) {
    strings(s);
    ints(t);
    v.eb(t, s);
  }
  sort(all(v), greater{});
  wt(v[1].second);
}
