#include <bits/stdc++.h>

#include "atcoder.h"
#include "mo.h"

void Main() {
  ints(n, q);
  V<int> c(n);
  cin >> c;
  V<pair<int, int>> qs;
  rep(i, q) {
    ints(l, r);
    qs.eb(l - 1, r);
  }

  V<int> kinds(n);
  int unique_kinds = 0;

  auto add = [&](int i) {
    if (kinds[c[i] - 1]++ == 0) ++unique_kinds;
  };
  auto del = [&](int i) {
    if (--kinds[c[i] - 1] == 0) --unique_kinds;
  };
  auto get = [&] { return unique_kinds; };

  each(e, Mo(add, del, get, qs)) wt(e);
}
