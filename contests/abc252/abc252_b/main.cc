#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(n, k);
    V<int> a(n), b(k);
    cin >> a >> b;
    V<bool> ng(n);
    each(e, b) ng[e - 1] = true;
    int m = max(a);
    rep(i, n) if (a[i] == m && ng[i]) return true;
    return false;
  }());
}
