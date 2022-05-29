#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  ints(q);
  rep(q) {
    ints(x, y);
    set<int> A, B;
    rep(i, x) A.insert(a[i]);
    rep(i, y) B.insert(b[i]);
    wt(A == B);
  }
}
