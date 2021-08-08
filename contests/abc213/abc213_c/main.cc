#include <bits/stdc++.h>

#include "atcoder.h"
#include "compress.h"

void Main() {
  ints(h, w, n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  V<int> ca = Compress(a), cb = Compress(b);
  rep(i, n) {
    int A = Uncompress(ca, a[i]);
    int B = Uncompress(cb, b[i]);
    wt(A + 1, B + 1);
  }
}
