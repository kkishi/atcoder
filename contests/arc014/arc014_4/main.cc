#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(all, n, m);
  V<int> l(n);
  cin >> l;
  V<int> L;
  rep(i, n - 1) L.pb(l[i + 1] - l[i] - 1);
  sort(L);
  V<int> s(n);
  rep(i, n - 1) s[i + 1] = s[i] + L[i];
  rep(m) {
    ints(x, y);
    int z = lower_bound(all(L), x + y + 1) - L.begin();
    wt(n + s[z] + ((n - 1) - z) * (x + y) + min(x, l[0] - 1) +
       min(y, all - l[n - 1]));
  }
}
