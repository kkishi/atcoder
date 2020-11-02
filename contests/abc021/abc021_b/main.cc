#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b, k);
  V<int> p(k);
  cin >> p;
  p.push_back(a);
  p.push_back(b);
  wt(sz(set(all(p))) == sz(p) ? "YES" : "NO");
}
