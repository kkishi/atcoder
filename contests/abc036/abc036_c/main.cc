#include <bits/stdc++.h>

#include "atcoder.h"
#include "compress.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> b = Compress(a);
  rep(i, n) wt(Uncompress(b, a[i]));
}
