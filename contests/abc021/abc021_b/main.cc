#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b, k);
  V<int> p(k);
  cin >> p;
  p.pb(a);
  p.pb(b);
  wt(sz(set(all(p))) == sz(p) ? "YES" : "NO");
}
