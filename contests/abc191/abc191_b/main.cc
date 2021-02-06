#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  V<int> b;
  each(ai, a) if (ai != x) b.pb(ai);
  rep(i, sz(b)) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;
}
