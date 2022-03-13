#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<string, int> m;
  rep(i, n) {
    strings(s);
    sort(s);
    ++m[s];
  }
  int ans = 0;
  each(_, cnt, m) ans += cnt * (cnt - 1) / 2;
  wt(ans);
}
