#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<int, int> m;
  rep(i, n) m[i + 1] = 0;
  rep(n) {
    ints(a);
    ++m[a];
  }
  int zero = -1, two = -1;
  for (auto [k, v] : m) {
    if (v == 0) {
      zero = k;
    }
    if (v == 2) {
      two = k;
    }
  }
  if (zero == -1) {
    wt("Correct");
  } else {
    wt(two, zero);
  }
}
