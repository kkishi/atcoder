#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  BIT<int> b(n);
  int x = 0;
  rep(i, n) {
    x += b.Sum(n - 1) - b.Sum(a[i]);
    b.Add(a[i], 1);
  }
  wt(x);
  rep(i, n - 1) {
    x -= a[i];
    x += n - 1 - a[i];
    wt(x);
  }
}
