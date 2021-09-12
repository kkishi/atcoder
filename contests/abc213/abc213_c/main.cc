#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"

void Main() {
  ints(h, w, n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  Compressor ca(a), cb(b);
  rep(i, n) {
    int A = ca(a[i]);
    int B = cb(b[i]);
    wt(A + 1, B + 1);
  }
}
