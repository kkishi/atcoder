#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([]() {
    ints(n, k);
    V<int> a(n);
    cin >> a;
    VV<int> b(k);
    rep(i, n) b[i % k].pb(a[i]);
    sort(a);
    each(e, b) sort(e);
    rep(i, n) if (a[i] != b[i % k][i / k]) return false;
    return true;
  }());
}
