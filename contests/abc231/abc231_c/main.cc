#include <bits/stdc++.h>

#include "atcoder.h"
#include "count.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  sort(a);
  rep(q) {
    ints(x);
    wt(CountGE(a, x));
  }
}
