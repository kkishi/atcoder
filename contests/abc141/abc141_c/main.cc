#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k, q);
  vector<int> v(n);
  rep(i, q) {
    ints(a);
    ++v[a - 1];
  }
  rep(i, n) wt(k > q - v[i]);
}
