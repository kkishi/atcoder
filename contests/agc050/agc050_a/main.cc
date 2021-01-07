#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  rep(i, 1, n + 1) {
    auto f = [&n](int x) { return (x - 1) % n + 1; };
    wt(f(i * 2), f(i * 2 + 1));
  }
}
