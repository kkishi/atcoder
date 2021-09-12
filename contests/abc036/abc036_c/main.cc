#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  Compressor b(a);
  rep(i, n) wt(b(a[i]));
}
