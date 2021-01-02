#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> v;
  int sum = 0;
  rep(n) {
    ints(a, b);
    sum -= a;
    v.push_back(a * 2 + b);
  }
  sort(all(v), greater{});
  rep(i, n) {
    sum += v[i];
    if (sum > 0) {
      wt(i + 1);
      return;
    }
  }
}
