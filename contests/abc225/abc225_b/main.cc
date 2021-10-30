#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<int, int> m;
  rep(n - 1) {
    ints(a, b);
    ++m[a];
    ++m[b];
  }
  bool ok = false;
  each(_, k, m) if (k == n - 1) ok = true;
  wt(ok);
}
