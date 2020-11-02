#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  map<int, int> m;
  rep(3) {
    ints(l);
    ++m[l];
  }
  for (auto [k, v] : m) {
    if (v == 1 || v == 3) wt(k);
  }
}
